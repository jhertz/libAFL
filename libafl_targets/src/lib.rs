//! `libafl_targets` contains runtime code, injected in the target itself during compilation.

include!(concat!(env!("OUT_DIR"), "/constants.rs"));

#[cfg(any(
    feature = "sancov_pcguard_edges",
    feature = "sancov_pcguard_hitcounts",
    feature = "sancov_pcguard_edges_ptr",
    feature = "sancov_pcguard_hitcounts_ptr"
))]
pub mod sancov_pcguard;
#[cfg(any(
    feature = "sancov_pcguard_edges",
    feature = "sancov_pcguard_hitcounts",
    feature = "sancov_pcguard_edges_ptr",
    feature = "sancov_pcguard_hitcounts_ptr"
))]
pub use sancov_pcguard::*;

#[cfg(any(feature = "sancov_cmplog", feature = "sancov_value_profile"))]
pub mod sancov_cmp;
#[cfg(any(feature = "sancov_cmplog", feature = "sancov_value_profile"))]
pub use sancov_cmp::*;

#[cfg(feature = "libfuzzer")]
pub mod libfuzzer;
#[cfg(feature = "libfuzzer")]
pub use libfuzzer::*;

pub mod coverage;
pub use coverage::*;

pub mod value_profile;
pub use value_profile::*;

pub mod cmplog;
pub use cmplog::*;

pub mod drcov;
