includeRoot = include_directories ( '.' )

compiler = meson.get_compiler ( 'cpp' )
if compiler.has_argument ( '-fdiagnostics-parseable-fixits' )
    add_project_arguments (
        '-fdiagnostics-parseable-fixits',
        language : 'cpp'
    )
endif

subdir ( 'hash' )
subdir ( 'test' )

main = executable (
    'main',
    'main.cpp',
    dependencies : hash_dep,
    install : true,
    install_rpath : '$ORIGIN',
)
