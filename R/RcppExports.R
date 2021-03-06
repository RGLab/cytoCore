# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

deep_copy_cytoframe <- function(fr) {
    .Call('_cytoCore_deep_copy_cytoframe', PACKAGE = 'cytoCore', fr)
}

shallow_copy_cytoframe <- function(fr) {
    .Call('_cytoCore_shallow_copy_cytoframe', PACKAGE = 'cytoCore', fr)
}

subset_cytoframe_by_rows <- function(fr, idx) {
    invisible(.Call('_cytoCore_subset_cytoframe_by_rows', PACKAGE = 'cytoCore', fr, idx))
}

subset_cytoframe_by_cols <- function(fr, idx) {
    invisible(.Call('_cytoCore_subset_cytoframe_by_cols', PACKAGE = 'cytoCore', fr, idx))
}

frm_compensate <- function(fr, spillover) {
    invisible(.Call('_cytoCore_frm_compensate', PACKAGE = 'cytoCore', fr, spillover))
}

get_spillover <- function(fr, key) {
    .Call('_cytoCore_get_spillover', PACKAGE = 'cytoCore', fr, key)
}

writeH5 <- function(fr, filename) {
    invisible(.Call('_cytoCore_writeH5', PACKAGE = 'cytoCore', fr, filename))
}

setMarker <- function(fr, old, new_name) {
    invisible(.Call('_cytoCore_setMarker', PACKAGE = 'cytoCore', fr, old, new_name))
}

setChannel <- function(fr, old, new_name) {
    invisible(.Call('_cytoCore_setChannel', PACKAGE = 'cytoCore', fr, old, new_name))
}

parseFCS <- function(filename, config, text_only = FALSE) {
    .Call('_cytoCore_parseFCS', PACKAGE = 'cytoCore', filename, config, text_only)
}

getData <- function(fr) {
    .Call('_cytoCore_getData', PACKAGE = 'cytoCore', fr)
}

getKeyword <- function(fr, key) {
    .Call('_cytoCore_getKeyword', PACKAGE = 'cytoCore', fr, key)
}

getKeywords <- function(fr) {
    .Call('_cytoCore_getKeywords', PACKAGE = 'cytoCore', fr)
}

setKeywords <- function(fr, keys) {
    invisible(.Call('_cytoCore_setKeywords', PACKAGE = 'cytoCore', fr, keys))
}

getncol <- function(fr) {
    .Call('_cytoCore_getncol', PACKAGE = 'cytoCore', fr)
}

getnrow <- function(fr) {
    .Call('_cytoCore_getnrow', PACKAGE = 'cytoCore', fr)
}

getpdata <- function(fr) {
    .Call('_cytoCore_getpdata', PACKAGE = 'cytoCore', fr)
}

isCytoLibOptimum <- function() {
    .Call('_cytoCore_isCytoLibOptimum', PACKAGE = 'cytoCore')
}

setLogLevel <- function(loglevel) {
    invisible(.Call('_cytoCore_setLogLevel', PACKAGE = 'cytoCore', loglevel))
}

fcs_to_cytoset <- function(sample_uid_vs_file_path, config, is_h5, h5_dir) {
    .Call('_cytoCore_fcs_to_cytoset', PACKAGE = 'cytoCore', sample_uid_vs_file_path, config, is_h5, h5_dir)
}

get_colnames <- function(cs) {
    .Call('_cytoCore_get_colnames', PACKAGE = 'cytoCore', cs)
}

copy_cytoset <- function(cs) {
    .Call('_cytoCore_copy_cytoset', PACKAGE = 'cytoCore', cs)
}

subset_cytoset_by_rows <- function(cs, sn, idx) {
    invisible(.Call('_cytoCore_subset_cytoset_by_rows', PACKAGE = 'cytoCore', cs, sn, idx))
}

subset_cytoset <- function(cs, i_obj, j_obj) {
    .Call('_cytoCore_subset_cytoset', PACKAGE = 'cytoCore', cs, i_obj, j_obj)
}

get_cytoFrame <- function(cs, i_obj, j_obj, useExpr) {
    .Call('_cytoCore_get_cytoFrame', PACKAGE = 'cytoCore', cs, i_obj, j_obj, useExpr)
}

get_pheno_data <- function(cs) {
    .Call('_cytoCore_get_pheno_data', PACKAGE = 'cytoCore', cs)
}

