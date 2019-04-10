project (
	'prj1',
	'cpp',
	default_options : [
		'cpp_std=c++17',
		'werror=true',
		'warning_level=3',
	],
	version : '0',
)
subdir ( 'src' )
if build_machine.system ( ) != 'windows'
	meson.add_install_script (
		'tar',
		'cJvf',
		'bin.tar.xz',
		'bin',
	)
else
    meson.add_install_script (
		'powershell.exe',
		'Compress-Archive',
		'-Force',
		'bin',
		'bin.zip'
	)
endif
