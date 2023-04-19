#' Rust tiktoken
#'
#' @export
#' @rdname rustTiktoken
#' @examples tokens_count("This is a test string")
#' @return token counts evaluating in Rust (number, and NULL respectively).
#' @useDynLib rustTiktoken tokens_count_wrapper
tokens_count <- function(text) {
  .Call(tokens_count_wrapper, text)
}
