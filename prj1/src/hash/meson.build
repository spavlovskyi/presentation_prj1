openssl_dep = dependency ( 'OpenSSL' )
gsl_microsoft_dep = dependency ( 'gsl_microsoft' )

hash_deps = [
    openssl_dep,
    gsl_microsoft_dep,
]

hash = static_library (
    'hash',
    'hash.cpp',
    dependencies : hash_deps,
    implicit_include_directories : false,
    include_directories : includeRoot,
)

hash_dep = declare_dependency (
    dependencies : hash_deps,
    link_with : hash,
    include_directories : includeRoot,
)
