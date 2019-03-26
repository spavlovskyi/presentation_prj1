includeRoot = include_directories ( '.' )


if meson.get_compiler ( 'cpp' ).has_argument ( '-fdiagnostics-parseable-fixits' )
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
)
