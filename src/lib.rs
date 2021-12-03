#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals)]
include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    use super::*;
    type Result<T> = ::std::result::Result<T, Box<dyn ::std::error::Error>>;

    #[test]
    fn test_inherited() -> Result<()> {
        dbg!("opening");
        unsafe {
            let config = newConfig();
            setInherited(config);
            dbg!("post-set");
            printInherited(config);
            dbg!("done");
            delConfig(config);
        }
        Ok(())
    }

    #[test]
    fn test_composed() -> Result<()> {
        dbg!("opening");
        unsafe {
            let config = newConfig();
            setComposed(config);
            dbg!("post-set");
            printComposed(config);
            dbg!("done");
            delConfig(config);
        }
        Ok(())
    }
}
