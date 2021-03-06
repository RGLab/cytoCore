// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "cytoCore_types.h"
#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// deep_copy_cytoframe
Rcpp::XPtr<CytoFrameView> deep_copy_cytoframe(Rcpp::XPtr<CytoFrameView> fr);
RcppExport SEXP _cytoCore_deep_copy_cytoframe(SEXP frSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    rcpp_result_gen = Rcpp::wrap(deep_copy_cytoframe(fr));
    return rcpp_result_gen;
END_RCPP
}
// shallow_copy_cytoframe
Rcpp::XPtr<CytoFrameView> shallow_copy_cytoframe(Rcpp::XPtr<CytoFrameView> fr);
RcppExport SEXP _cytoCore_shallow_copy_cytoframe(SEXP frSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    rcpp_result_gen = Rcpp::wrap(shallow_copy_cytoframe(fr));
    return rcpp_result_gen;
END_RCPP
}
// subset_cytoframe_by_rows
void subset_cytoframe_by_rows(Rcpp::XPtr<CytoFrameView> fr, vector<unsigned> idx);
RcppExport SEXP _cytoCore_subset_cytoframe_by_rows(SEXP frSEXP, SEXP idxSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    Rcpp::traits::input_parameter< vector<unsigned> >::type idx(idxSEXP);
    subset_cytoframe_by_rows(fr, idx);
    return R_NilValue;
END_RCPP
}
// subset_cytoframe_by_cols
void subset_cytoframe_by_cols(Rcpp::XPtr<CytoFrameView> fr, vector<unsigned> idx);
RcppExport SEXP _cytoCore_subset_cytoframe_by_cols(SEXP frSEXP, SEXP idxSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    Rcpp::traits::input_parameter< vector<unsigned> >::type idx(idxSEXP);
    subset_cytoframe_by_cols(fr, idx);
    return R_NilValue;
END_RCPP
}
// frm_compensate
void frm_compensate(Rcpp::XPtr<CytoFrameView> fr, NumericMatrix spillover);
RcppExport SEXP _cytoCore_frm_compensate(SEXP frSEXP, SEXP spilloverSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type spillover(spilloverSEXP);
    frm_compensate(fr, spillover);
    return R_NilValue;
END_RCPP
}
// get_spillover
NumericMatrix get_spillover(Rcpp::XPtr<CytoFrameView> fr, string key);
RcppExport SEXP _cytoCore_get_spillover(SEXP frSEXP, SEXP keySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    Rcpp::traits::input_parameter< string >::type key(keySEXP);
    rcpp_result_gen = Rcpp::wrap(get_spillover(fr, key));
    return rcpp_result_gen;
END_RCPP
}
// writeH5
void writeH5(Rcpp::XPtr<CytoFrameView> fr, string filename);
RcppExport SEXP _cytoCore_writeH5(SEXP frSEXP, SEXP filenameSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    Rcpp::traits::input_parameter< string >::type filename(filenameSEXP);
    writeH5(fr, filename);
    return R_NilValue;
END_RCPP
}
// setMarker
void setMarker(Rcpp::XPtr<CytoFrameView> fr, string old, string new_name);
RcppExport SEXP _cytoCore_setMarker(SEXP frSEXP, SEXP oldSEXP, SEXP new_nameSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    Rcpp::traits::input_parameter< string >::type old(oldSEXP);
    Rcpp::traits::input_parameter< string >::type new_name(new_nameSEXP);
    setMarker(fr, old, new_name);
    return R_NilValue;
END_RCPP
}
// setChannel
void setChannel(Rcpp::XPtr<CytoFrameView> fr, string old, string new_name);
RcppExport SEXP _cytoCore_setChannel(SEXP frSEXP, SEXP oldSEXP, SEXP new_nameSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    Rcpp::traits::input_parameter< string >::type old(oldSEXP);
    Rcpp::traits::input_parameter< string >::type new_name(new_nameSEXP);
    setChannel(fr, old, new_name);
    return R_NilValue;
END_RCPP
}
// parseFCS
Rcpp::XPtr<CytoFrameView> parseFCS(string filename, FCS_READ_PARAM config, bool text_only);
RcppExport SEXP _cytoCore_parseFCS(SEXP filenameSEXP, SEXP configSEXP, SEXP text_onlySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< string >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< FCS_READ_PARAM >::type config(configSEXP);
    Rcpp::traits::input_parameter< bool >::type text_only(text_onlySEXP);
    rcpp_result_gen = Rcpp::wrap(parseFCS(filename, config, text_only));
    return rcpp_result_gen;
END_RCPP
}
// getData
NumericVector getData(Rcpp::XPtr<CytoFrameView> fr);
RcppExport SEXP _cytoCore_getData(SEXP frSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    rcpp_result_gen = Rcpp::wrap(getData(fr));
    return rcpp_result_gen;
END_RCPP
}
// getKeyword
string getKeyword(Rcpp::XPtr<CytoFrameView> fr, string key);
RcppExport SEXP _cytoCore_getKeyword(SEXP frSEXP, SEXP keySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    Rcpp::traits::input_parameter< string >::type key(keySEXP);
    rcpp_result_gen = Rcpp::wrap(getKeyword(fr, key));
    return rcpp_result_gen;
END_RCPP
}
// getKeywords
KW_PAIR getKeywords(Rcpp::XPtr<CytoFrameView> fr);
RcppExport SEXP _cytoCore_getKeywords(SEXP frSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    rcpp_result_gen = Rcpp::wrap(getKeywords(fr));
    return rcpp_result_gen;
END_RCPP
}
// setKeywords
void setKeywords(Rcpp::XPtr<CytoFrameView> fr, List keys);
RcppExport SEXP _cytoCore_setKeywords(SEXP frSEXP, SEXP keysSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    Rcpp::traits::input_parameter< List >::type keys(keysSEXP);
    setKeywords(fr, keys);
    return R_NilValue;
END_RCPP
}
// getncol
int getncol(Rcpp::XPtr<CytoFrameView> fr);
RcppExport SEXP _cytoCore_getncol(SEXP frSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    rcpp_result_gen = Rcpp::wrap(getncol(fr));
    return rcpp_result_gen;
END_RCPP
}
// getnrow
int getnrow(Rcpp::XPtr<CytoFrameView> fr);
RcppExport SEXP _cytoCore_getnrow(SEXP frSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    rcpp_result_gen = Rcpp::wrap(getnrow(fr));
    return rcpp_result_gen;
END_RCPP
}
// getpdata
Rcpp::DataFrame getpdata(Rcpp::XPtr<CytoFrameView> fr);
RcppExport SEXP _cytoCore_getpdata(SEXP frSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoFrameView> >::type fr(frSEXP);
    rcpp_result_gen = Rcpp::wrap(getpdata(fr));
    return rcpp_result_gen;
END_RCPP
}
// isCytoLibOptimum
bool isCytoLibOptimum();
RcppExport SEXP _cytoCore_isCytoLibOptimum() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(isCytoLibOptimum());
    return rcpp_result_gen;
END_RCPP
}
// setLogLevel
void setLogLevel(unsigned short loglevel);
RcppExport SEXP _cytoCore_setLogLevel(SEXP loglevelSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned short >::type loglevel(loglevelSEXP);
    setLogLevel(loglevel);
    return R_NilValue;
END_RCPP
}
// fcs_to_cytoset
Rcpp::XPtr<CytoSet> fcs_to_cytoset(vector<pair<string,string>> sample_uid_vs_file_path, const FCS_READ_PARAM& config, bool is_h5, string h5_dir);
RcppExport SEXP _cytoCore_fcs_to_cytoset(SEXP sample_uid_vs_file_pathSEXP, SEXP configSEXP, SEXP is_h5SEXP, SEXP h5_dirSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< vector<pair<string,string>> >::type sample_uid_vs_file_path(sample_uid_vs_file_pathSEXP);
    Rcpp::traits::input_parameter< const FCS_READ_PARAM& >::type config(configSEXP);
    Rcpp::traits::input_parameter< bool >::type is_h5(is_h5SEXP);
    Rcpp::traits::input_parameter< string >::type h5_dir(h5_dirSEXP);
    rcpp_result_gen = Rcpp::wrap(fcs_to_cytoset(sample_uid_vs_file_path, config, is_h5, h5_dir));
    return rcpp_result_gen;
END_RCPP
}
// get_colnames
vector<string> get_colnames(Rcpp::XPtr<CytoSet> cs);
RcppExport SEXP _cytoCore_get_colnames(SEXP csSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoSet> >::type cs(csSEXP);
    rcpp_result_gen = Rcpp::wrap(get_colnames(cs));
    return rcpp_result_gen;
END_RCPP
}
// copy_cytoset
Rcpp::XPtr<CytoSet> copy_cytoset(Rcpp::XPtr<CytoSet> cs);
RcppExport SEXP _cytoCore_copy_cytoset(SEXP csSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoSet> >::type cs(csSEXP);
    rcpp_result_gen = Rcpp::wrap(copy_cytoset(cs));
    return rcpp_result_gen;
END_RCPP
}
// subset_cytoset_by_rows
void subset_cytoset_by_rows(Rcpp::XPtr<CytoSet> cs, string sn, vector<unsigned> idx);
RcppExport SEXP _cytoCore_subset_cytoset_by_rows(SEXP csSEXP, SEXP snSEXP, SEXP idxSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoSet> >::type cs(csSEXP);
    Rcpp::traits::input_parameter< string >::type sn(snSEXP);
    Rcpp::traits::input_parameter< vector<unsigned> >::type idx(idxSEXP);
    subset_cytoset_by_rows(cs, sn, idx);
    return R_NilValue;
END_RCPP
}
// subset_cytoset
Rcpp::XPtr<CytoSet> subset_cytoset(Rcpp::XPtr<CytoSet> cs, SEXP i_obj, SEXP j_obj);
RcppExport SEXP _cytoCore_subset_cytoset(SEXP csSEXP, SEXP i_objSEXP, SEXP j_objSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoSet> >::type cs(csSEXP);
    Rcpp::traits::input_parameter< SEXP >::type i_obj(i_objSEXP);
    Rcpp::traits::input_parameter< SEXP >::type j_obj(j_objSEXP);
    rcpp_result_gen = Rcpp::wrap(subset_cytoset(cs, i_obj, j_obj));
    return rcpp_result_gen;
END_RCPP
}
// get_cytoFrame
Rcpp::XPtr<CytoFrameView> get_cytoFrame(Rcpp::XPtr<CytoSet> cs, Rcpp::RObject i_obj, Rcpp::RObject j_obj, bool useExpr);
RcppExport SEXP _cytoCore_get_cytoFrame(SEXP csSEXP, SEXP i_objSEXP, SEXP j_objSEXP, SEXP useExprSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoSet> >::type cs(csSEXP);
    Rcpp::traits::input_parameter< Rcpp::RObject >::type i_obj(i_objSEXP);
    Rcpp::traits::input_parameter< Rcpp::RObject >::type j_obj(j_objSEXP);
    Rcpp::traits::input_parameter< bool >::type useExpr(useExprSEXP);
    rcpp_result_gen = Rcpp::wrap(get_cytoFrame(cs, i_obj, j_obj, useExpr));
    return rcpp_result_gen;
END_RCPP
}
// get_pheno_data
List get_pheno_data(Rcpp::XPtr<CytoSet> cs);
RcppExport SEXP _cytoCore_get_pheno_data(SEXP csSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<CytoSet> >::type cs(csSEXP);
    rcpp_result_gen = Rcpp::wrap(get_pheno_data(cs));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_cytoCore_deep_copy_cytoframe", (DL_FUNC) &_cytoCore_deep_copy_cytoframe, 1},
    {"_cytoCore_shallow_copy_cytoframe", (DL_FUNC) &_cytoCore_shallow_copy_cytoframe, 1},
    {"_cytoCore_subset_cytoframe_by_rows", (DL_FUNC) &_cytoCore_subset_cytoframe_by_rows, 2},
    {"_cytoCore_subset_cytoframe_by_cols", (DL_FUNC) &_cytoCore_subset_cytoframe_by_cols, 2},
    {"_cytoCore_frm_compensate", (DL_FUNC) &_cytoCore_frm_compensate, 2},
    {"_cytoCore_get_spillover", (DL_FUNC) &_cytoCore_get_spillover, 2},
    {"_cytoCore_writeH5", (DL_FUNC) &_cytoCore_writeH5, 2},
    {"_cytoCore_setMarker", (DL_FUNC) &_cytoCore_setMarker, 3},
    {"_cytoCore_setChannel", (DL_FUNC) &_cytoCore_setChannel, 3},
    {"_cytoCore_parseFCS", (DL_FUNC) &_cytoCore_parseFCS, 3},
    {"_cytoCore_getData", (DL_FUNC) &_cytoCore_getData, 1},
    {"_cytoCore_getKeyword", (DL_FUNC) &_cytoCore_getKeyword, 2},
    {"_cytoCore_getKeywords", (DL_FUNC) &_cytoCore_getKeywords, 1},
    {"_cytoCore_setKeywords", (DL_FUNC) &_cytoCore_setKeywords, 2},
    {"_cytoCore_getncol", (DL_FUNC) &_cytoCore_getncol, 1},
    {"_cytoCore_getnrow", (DL_FUNC) &_cytoCore_getnrow, 1},
    {"_cytoCore_getpdata", (DL_FUNC) &_cytoCore_getpdata, 1},
    {"_cytoCore_isCytoLibOptimum", (DL_FUNC) &_cytoCore_isCytoLibOptimum, 0},
    {"_cytoCore_setLogLevel", (DL_FUNC) &_cytoCore_setLogLevel, 1},
    {"_cytoCore_fcs_to_cytoset", (DL_FUNC) &_cytoCore_fcs_to_cytoset, 4},
    {"_cytoCore_get_colnames", (DL_FUNC) &_cytoCore_get_colnames, 1},
    {"_cytoCore_copy_cytoset", (DL_FUNC) &_cytoCore_copy_cytoset, 1},
    {"_cytoCore_subset_cytoset_by_rows", (DL_FUNC) &_cytoCore_subset_cytoset_by_rows, 3},
    {"_cytoCore_subset_cytoset", (DL_FUNC) &_cytoCore_subset_cytoset, 3},
    {"_cytoCore_get_cytoFrame", (DL_FUNC) &_cytoCore_get_cytoFrame, 4},
    {"_cytoCore_get_pheno_data", (DL_FUNC) &_cytoCore_get_pheno_data, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_cytoCore(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
