// Import dependencies
extern crate libc;
extern crate tiktoken_rs;

// Modules are other .rs source files
mod tiktoken;

// Export functions called by R
pub use tiktoken::token_count_from_rust;
