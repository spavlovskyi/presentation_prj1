openssl_dep = dependency ( 'OpenSSL' )
gsl_microsoft_dep = dependency ( 'gsl_microsoft' )

hash_deps = [
    openssl_dep,
    gsl_microsoft_dep,
]
hash_cpp_args = [ ]
if compiler.get_id ( ) == 'msvc'
    hash_cpp_args += '/wd4701'
endif

hash = static_library (
    'hash',
    'hash.cpp',
    cpp_args : hash_cpp_args,
    dependencies : hash_deps,
    implicit_include_directories : false,
    include_directories : includeRoot,
)

hash_dep = declare_dependency (
    dependencies : hash_deps,
    link_with : hash,
    include_directories : includeRoot,
)
