#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals)]
include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    use super::root::*;
    type Result<T> = ::std::result::Result<T, Box<dyn ::std::error::Error>>;

    #[test]
    fn test_map() -> Result<()> {
        let mut config = Configuration::default();
        unsafe {
            dbg!("before");
            // config.set_inherited();
            config.set_composed();
            dbg!("between");
            // config.print_inherited();
            config.print_composed();
        }
        Ok(())
    }
}
