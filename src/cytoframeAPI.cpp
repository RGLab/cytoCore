#include <cytoCore/pairVectorRcppWrap.h>
using namespace Rcpp;
using namespace cytolib;
 

// [[Rcpp::export]]
string get_h5_file_path(Rcpp::XPtr<CytoFrameView> fr)
{
	return fr->get_h5_file_path();
}

// [[Rcpp::export]]
Rcpp::XPtr<CytoFrameView> deep_copy_cytoframe(Rcpp::XPtr<CytoFrameView> fr)
{
 return XPtr<CytoFrameView>(new CytoFrameView(fr->copy()));
}

// [[Rcpp::export]]
Rcpp::XPtr<CytoFrameView> shallow_copy_cytoframe(Rcpp::XPtr<CytoFrameView> fr)
{
  return XPtr<CytoFrameView>(new CytoFrameView(*fr));
}

// [[Rcpp::export]]
void subset_cytoframe_by_rows(Rcpp::XPtr<CytoFrameView> fr, vector<unsigned> idx)
{
  
  fr->rows_(idx);
}

// [[Rcpp::export]]
void subset_cytoframe_by_cols(Rcpp::XPtr<CytoFrameView> fr, vector<unsigned> idx)
{
  
  fr->cols_(idx);
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
void frm_compensate(Rcpp::XPtr<CytoFrameView> fr, NumericMatrix spillover){
  vector<string> marker = as<vector<string>>(colnames(spillover));
  mat spill = as<mat>(spillover);
  // spill.print(Rcout, "spill");
  compensation comp(spill, marker);
  // comp.get_spillover_mat().print(Rcout, "comp");
  fr->compensate(comp);
}
// [[Rcpp::export]] 
NumericMatrix get_spillover(Rcpp::XPtr<CytoFrameView> fr, string key){
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
void writeH5(Rcpp::XPtr<CytoFrameView> fr, string filename){
  fr->write_h5(filename);
  
}

// [[Rcpp::export]] 
void setMarker(Rcpp::XPtr<CytoFrameView> fr, string old, string new_name){
  fr->set_marker(old, new_name);
}                                      

// [[Rcpp::export]] 
void setChannel(Rcpp::XPtr<CytoFrameView> fr, string old, string new_name){
  fr->set_channel(old, new_name);
}                                      
                                      
// [[Rcpp::export]] 
Rcpp::XPtr<CytoFrameView> parseFCS(string filename, FCS_READ_PARAM config, bool text_only = false)
{

    unique_ptr<MemCytoFrame> fr(new MemCytoFrame(filename.c_str(), config));
    if(text_only)
      fr->read_fcs_header();
    else
      fr->read_fcs();
    return Rcpp::XPtr<CytoFrameView>(new CytoFrameView(CytoFramePtr(fr.release())));

}

// [[Rcpp::export]] 
NumericVector getData(Rcpp::XPtr<CytoFrameView> fr){
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
string getKeyword(Rcpp::XPtr<CytoFrameView> fr, string key){
  
  string res = fr->get_keyword(key);
  return res;
}

// [[Rcpp::export]] 
KW_PAIR getKeywords(Rcpp::XPtr<CytoFrameView> fr){
  // return fr->getKeywords().getPairs();
  return fr->get_keywords().getPairs();
}

// [[Rcpp::export]] 
void setKeywords(Rcpp::XPtr<CytoFrameView> fr, List keys){
    vector<string> names = keys.names();
    for(int i = 0; i < keys.size(); i++) 
      fr->set_keyword(names[i], keys[i]);
}
// [[Rcpp::export]] 
int getncol(Rcpp::XPtr<CytoFrameView> fr){
  
  return fr->n_cols();
}

// [[Rcpp::export]] 
int getnrow(Rcpp::XPtr<CytoFrameView> fr){
  
  return fr->n_rows();
}

// [[Rcpp::export]] 
Rcpp::DataFrame getpdata(Rcpp::XPtr<CytoFrameView> fr){
  
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
