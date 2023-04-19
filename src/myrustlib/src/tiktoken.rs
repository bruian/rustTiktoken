use std;
use std::ffi::CStr;
use std::os::raw::c_int;
use std::os::raw::c_char;
use tiktoken_rs::p50k_base;

#[no_mangle]
pub extern fn token_count_from_rust(token_string: *const c_char) -> c_int {
    unsafe {
        let s = CStr::from_ptr(token_string);
        let bpe = p50k_base().unwrap();
        let tokens = bpe.encode_with_special_tokens(s.to_str().unwrap());
        std::mem::forget(s);
        tokens.len() as c_int
    }
}
