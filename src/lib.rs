#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals)]
include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    // use super::root::*;
    use super::*;
    type Result<T> = ::std::result::Result<T, Box<dyn ::std::error::Error>>;

    #[test]
    fn test_map() -> Result<()> {
        dbg!("opening");
        let mut config = std::mem::MaybeUninit::uninit();
        unsafe {
            dbg!("pre-set");
            // config.set_composed();
            Configuration_set_inherited(config.as_mut_ptr());
            let mut config = config.assume_init();
            dbg!("post-set");
            // config.print_composed();
            config.print_inherited();
            dbg!("done");
        }
        Ok(())
    }
}
