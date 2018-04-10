---
output: 
  html_document: 
    keep_md: yes
---

cytoCore
========

R bindings of the Core cytometry infrastructure

Installation
========

```r
devtools::install_github("RGLab/RProtoBufLib", ref = "cytoset")
devtools::install_github("RGLab/cytolib", ref = "cytoset")
devtools::install_github("RGLab/cytoCore")
```

CytoFrame
========

```r
library(cytoCore)
```

```
## Loading required package: flowCore
```

```r
files <- list.files(pattern = ".fcs", "../flowWorkspace/wsTestSuite/curlyQuad/example1/", full.names = T)
fr <- load_cytoframe_from_fcs(files[1])
fr
```

```
## cytoFrame object 'A1001.001.fcs'
## with 10045 cells and 9 observables:
##              name               desc  range minRange maxRange
## $P1          Time               <NA> 262143      0.0   262143
## $P2         FSC-H              FSC-H 262143      0.0   262143
## $P3         SSC-A              SSC-A 262143   -111.0   262143
## $P4        FITC-A         CD3 FITC-A 262143    -72.8   262143
## $P5          PE-A       CD16+56 PE-A 262143   -111.0   262143
## $P6 PerCP-Cy5-5-A CD45 PerCP-Cy5-5-A 262143      0.0   262143
## $P7      PE-Cy7-A       CD4 PE-Cy7-A 262143   -111.0   262143
## $P8         APC-A         CD19 APC-A 262143   -111.0   262143
## $P9     APC-Cy7-A      CD8 APC-Cy7-A 262143   -111.0   262143
## 136 keywords are stored in the 'description' slot
```

```r
#accessors
dim(fr)
```

```
##     events parameters 
##      10045          9
```

```r
colnames(fr)
```

```
## [1] "Time"          "FSC-H"         "SSC-A"         "FITC-A"       
## [5] "PE-A"          "PerCP-Cy5-5-A" "PE-Cy7-A"      "APC-A"        
## [9] "APC-Cy7-A"
```

```r
#fetch data
head(exprs(fr))
```

```
##      Time  FSC-H    SSC-A  FITC-A    PE-A PerCP-Cy5-5-A PE-Cy7-A     APC-A
## [1,] 9218 111270 250185.6   327.6   861.0        1892.8   1300.6    472.50
## [2,] 9220  84343  18131.4    86.8  4090.8       12282.2   3043.6    602.28
## [3,] 9224  97837  20741.0    68.6  2037.0       15580.6   3969.0   1034.46
## [4,] 9226   8265 214078.2 18295.2 59862.6       51328.2   7362.6 184035.59
## [5,] 9229  78488  27791.4  1587.6   700.0        8748.6   2926.0   1838.34
## [6,] 9238  74717  16717.4   754.6   564.2        9685.2  12912.2    424.62
##      APC-Cy7-A
## [1,]   1125.18
## [2,]    967.68
## [3,]   4334.40
## [4,]  31511.34
## [5,]  10877.58
## [6,]   1978.20
```

Read header only
========

```r
fr1 <- load_cytoframe_from_fcs(files[1], text.only = T)
nrow(fr1)
```

```
## [1] 0
```

```r
spillover(fr1)
```

```
##            FITC-A         PE-A PerCP-Cy5-5-A    PE-Cy7-A        APC-A
## [1,] 1.0000000000 0.2451506319   0.029113146 0.004691324 0.0000000000
## [2,] 0.0136447796 1.0000000000   0.127052776 0.015378953 0.0017716167
## [3,] 0.0001986171 0.0010141377   1.000000000 0.268173511 0.0640295539
## [4,] 0.0023550167 0.0163842613   0.029222466 1.000000000 0.0006842251
## [5,] 0.0000000000 0.0000000000   0.006464045 0.001500996 1.0000000000
## [6,] 0.0000585031 0.0001086252   0.000719197 0.013939872 0.0523514199
##         APC-Cy7-A
## [1,] 0.0000000000
## [2,] 0.0006741632
## [3,] 0.1567523517
## [4,] 0.0976535448
## [5,] 0.0844181958
## [6,] 1.0000000000
```

```r
#keyword
head(keyword(fr1))
```

```
## $FCSversion
## [1] "3"
## 
## $`$NEXTDATA`
## [1] "0"
## 
## $`$SYS`
## [1] "Win32NT"
## 
## $`$BEGINDATA`
## [1] "2589"
## 
## $`$ENDDATA`
## [1] "364208"
## 
## $`$BEGINANALYSIS`
## [1] "364209"
```

Parallel read
========

```r
fr <- load_cytoframe_from_fcs(files[3], num_threads = 3)
```

Pass by reference
=========

```r
fr1 <- fr #fr1 is a reference
colnames(fr1)[1]
```

```
## [1] "Time"
```

```r
colnames(fr1)[1] <- "t"
colnames(fr)[1] # change affects the original fr object
```

```
## [1] "t"
```

Shallow copy
=========

```r
fr1 <- fr[1:10, 2:3] #subsetting is cheap since it is merely a view of orignal fr
#they both share the same underlying data pointer
# exprs(fr1)[2] <- 0 # data change affects the orignal fr

dim(fr1)
```

```
##     events parameters 
##         10          2
```

```r
dim(fr)
```

```
##     events parameters 
##      10045          9
```

Deep copy
=========

```r
fr1 <- deep_copy(fr) #fr1 is independent copy
```

Coerce to flowFrame
=========

```r
as.flowFrame(fr)
```

```
## flowFrame object 'A3003.001.fcs'
## with 10045 cells and 9 observables:
##              name               desc  range minRange maxRange
## $P1             t               <NA> 262143      0.0   262143
## $P2         FSC-H              FSC-H 262143      0.0   262143
## $P3         SSC-A              SSC-A 262143   -111.0   262143
## $P4        FITC-A         CD3 FITC-A 262143   -103.6   262143
## $P5          PE-A       CD16+56 PE-A 262143   -111.0   262143
## $P6 PerCP-Cy5-5-A CD45 PerCP-Cy5-5-A 262143      0.0   262143
## $P7      PE-Cy7-A       CD4 PE-Cy7-A 262143   -111.0   262143
## $P8         APC-A         CD19 APC-A 262143   -111.0   262143
## $P9     APC-Cy7-A      CD8 APC-Cy7-A 262143   -111.0   262143
## 136 keywords are stored in the 'description' slot
```

Save to h5
======

```r
tmpfile <- tempfile(fileext = ".h5")
write.h5(fr, tmpfile)
library(rhdf5)
h5 <- H5Fopen(tmpfile)
h5
```

```
## HDF5 FILE
##         name /
##     filename 
## 
##       name       otype   dclass       dim
## 0 data     H5I_DATASET FLOAT    10045 x 9
## 1 keywords H5I_DATASET COMPOUND 136      
## 2 params   H5I_DATASET COMPOUND 9        
## 3 pdata    H5I_DATASET COMPOUND 0
```

```r
H5Fclose(h5)
```



