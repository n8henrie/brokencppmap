pub use crate::ffi::Configuration;
use cxx::UniquePtr;

#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("brokencppmap/wrapper.h");

        type Configuration;

        fn new_configuration() -> UniquePtr<Configuration>;
        fn set_composed(self: Pin<&mut Configuration>);
        fn print_composed(self: Pin<&mut Configuration>);
        fn set_inherited(self: Pin<&mut Configuration>);
        fn print_inherited(self: Pin<&mut Configuration>);
    }
}

impl Configuration {
    pub fn new() -> UniquePtr<Self> {
        ffi::new_configuration()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_inherited() {
        dbg!("opening");
        let mut config = Configuration::new();
        config.pin_mut().set_inherited();
        dbg!("post-set");
        config.pin_mut().print_inherited();
        dbg!("done");
    }

    #[test]
    fn test_composed() {
        dbg!("opening");
        let mut config = Configuration::new();
        config.pin_mut().set_composed();
        dbg!("post-set");
        config.pin_mut().print_composed();
        dbg!("done");
    }
}
