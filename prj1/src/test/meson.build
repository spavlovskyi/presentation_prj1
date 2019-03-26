boost_test_dep = dependency ( 'boost_test' )

run = executable (
    'run',
    'test.cpp',
    'hash.cpp',
    cpp_args : '-DBOOST_ALL_DYN_LINK',
    dependencies : [
        boost_test_dep,
        hash_dep,
    ],
    
)
test (
    'boost unit tests',
    run,
)
