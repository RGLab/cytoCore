#include <cytoCore/pairVectorRcppWrap.h>
using namespace Rcpp;
using namespace cytolib;
#ifdef PRT
 bool isOptimum = true;

 
// [[Rcpp::export]]
Rcpp::XPtr<CytoFrame> copy_Cytoframe(Rcpp::XPtr<CytoFrame> fr)
{
 return XPtr<CytoFrame>(fr->copy().release());
}


// [[Rcpp::export]]
void subset_cytoframe_by_rows(Rcpp::XPtr<CytoFrame> fr, vector<unsigned> idx)
{
  
  fr->rows_(idx);
}

// [[Rcpp::export]]
void subset_cytoframe_by_cols(Rcpp::XPtr<CytoFrame> fr, vector<string> cols)
{
  
  fr->cols_(cols, ColType::channel);
}
 /*
  * subset by cols and rows in place for each frames
  */  
 
 // unsigned short r_type = TYPEOF(r_obj);
 // // Rcout << "r_type:" << r_type << endl;  
 // for(auto & it : *cs_new)
 // {
 //   if(j_type != NILSXP)
 //     it.second->cols_(ch_selected, ColType::channel);
 //   if(r_type != NILSXP)
 //     it.second->rows_(convert_to_uint_idx(it.second->n_rows(), r_obj));
 // }
 
 
// [[Rcpp::export]] 
void frm_compensate(Rcpp::XPtr<CytoFrame> fr, NumericMatrix spillover){
  vector<string> marker = as<vector<string>>(colnames(spillover));
  mat spill = as<mat>(spillover);
  // spill.print(Rcout, "spill");
  compensation comp(spill, marker);
  // comp.get_spillover_mat().print(Rcout, "comp");
  fr->compensate(comp);
}
// [[Rcpp::export]] 
NumericMatrix get_spillover(Rcpp::XPtr<CytoFrame> fr, string key){
	compensation comp = fr->get_compensation(key);
  // Rcout << comp.marker.size() << endl;
  // Rcout << comp.spillOver.size() << endl;
	arma::mat spillover = comp.get_spillover_mat();
	// Rcpp::RcogetPairsut << spillover << endl;
	NumericMatrix res(Rcpp::wrap(spillover));//can't directly convert arma::mat to NumericMatrix
	colnames(res) = StringVector(wrap(comp.marker));
	// return Rcpp::List::create(spillover, comp.marker);
	return res;
}

// [[Rcpp::export]]
void writeH5(Rcpp::XPtr<CytoFrame> fr, string filename){
  fr->write_h5(filename);
  
}

// [[Rcpp::export]] 
void setMarker(Rcpp::XPtr<CytoFrame> fr, string old, string new_name){
  fr->set_marker(old, new_name);
}                                      

// [[Rcpp::export]] 
void setChannel(Rcpp::XPtr<CytoFrame> fr, string old, string new_name){
  fr->set_channel(old, new_name);
}                                      
                                      
// [[Rcpp::export]] 
Rcpp::XPtr<MemCytoFrame> parseFCS(string filename, FCS_READ_PARAM config, bool text_only = false)
{

    Rcpp::XPtr<MemCytoFrame> fr(new MemCytoFrame(filename.c_str(), config));
    if(text_only)
      fr->read_fcs_header();
    else
      fr->read_fcs();
    return fr;

}

// [[Rcpp::export]] 
NumericVector getData(Rcpp::XPtr<CytoFrame> fr){
  // int nrow = fr->n_rows();
  int ncol = fr->n_cols();
  // int ntotal = ncol * nrow;
  
  EVENT_DATA_VEC dat = fr->get_data();
  NumericMatrix mat = wrap(dat);
  // mat.attr("dim") = Dimension(nrow, ncol);
  StringVector chnl = wrap(fr->get_channels());
  StringVector cid(ncol);
  for(int i = 0; i < ncol; i++)
    cid[i] = "$P" + to_string(i+1) + "N";
  
    
  chnl.attr("names") = cid;
  mat.attr("dimnames") = List::create(R_NilValue, chnl);
  return mat;
}

// [[Rcpp::export]] 
string getKeyword(Rcpp::XPtr<CytoFrame> fr, string key){
  
  string res = fr->get_keyword(key);
  return res;
}

// [[Rcpp::export]] 
KW_PAIR getKeywords(Rcpp::XPtr<CytoFrame> fr){
  // return fr->getKeywords().getPairs();
  return fr->get_keywords().getPairs();
}

// [[Rcpp::export]] 
void setKeywords(Rcpp::XPtr<CytoFrame> fr, List keys){
    vector<string> names = keys.names();
    for(int i = 0; i < keys.size(); i++) 
      fr->set_keyword(names[i], keys[i]);
}
// [[Rcpp::export]] 
int getncol(Rcpp::XPtr<CytoFrame> fr){
  
  return fr->n_cols();
}

// [[Rcpp::export]] 
int getnrow(Rcpp::XPtr<CytoFrame> fr){
  
  return fr->n_rows();
}

// [[Rcpp::export]] 
Rcpp::DataFrame getpdata(Rcpp::XPtr<CytoFrame> fr){
  
  int ncol = fr->n_cols();
  StringVector rowid(ncol);
  StringVector names(ncol);
  StringVector desc(ncol);
  NumericVector range(ncol);
  NumericVector minRange(ncol);
  NumericVector maxRange(ncol);
  vector<string> chnl = fr->get_channels();
  vector<string> marker = fr->get_markers();
  for(int i = 0; i < ncol; i++)
  {
    rowid[i] = "$P" + to_string(i+1);
    names[i] = chnl[i];
    if(marker[i].empty())
      desc[i] = StringVector::get_na();
    else
      desc[i] = marker[i];
    pair<float, float> r = fr->get_range(chnl[i], ColType::channel, RangeType::instrument);
    maxRange[i] = range[i] = r.second;
    minRange[i] = r.first;
  }
  rowid.attr("class") = "AsIs";
  desc.attr("class") = "AsIs";
  names.attr("class") = "AsIs";
  DataFrame df = DataFrame::create(Named("name") = names
                             ,Named("desc") = desc
                             ,Named("range") = range
                             ,Named("minRange") = minRange
                             ,Named("maxRange") = maxRange
                             );
  df.attr("row.names") = rowid;
  return df;
}
#else
bool isOptimum = false;
#endif

// [[Rcpp::export]]
bool isCytoLibOptimum(){return isOptimum;}