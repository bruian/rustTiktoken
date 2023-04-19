#define R_NO_REMAP
#define STRICT_R_HEADERS
#include <Rinternals.h>

// Import C headers for rust API
#include "myrustlib/api.h"

// Actual Wrappers
SEXP tokens_count_wrapper(SEXP stringOfTokens){
  if(!Rf_isString(stringOfTokens))
    Rf_error("Argument stringOfTokens must be strings");

  return Rf_ScalarInteger(token_count_from_rust(CHAR(STRING_ELT(stringOfTokens, 0))));
}

// Standard R package stuff
static const R_CallMethodDef CallEntries[] = {
  {"tokens_count_wrapper", (DL_FUNC) &tokens_count_wrapper, 1},
  {NULL, NULL, 0}
};

void R_init_rustTiktoken(DllInfo *dll) {
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
