setlocal
if "%1"=="" (
	set config=vs
) else (
	set config=%1
)
set builddir=out\%config%
cd %~dp0
call config-%config%.bat
mkdir %builddir%
cd %builddir%
conan install ../.. --build=missing -s build_type=%conan_buildtype%
if %errorlevel% neq 0 exit /b %errorlevel%
rmdir /s /q meson-private
set PKG_CONFIG_PATH=%cd%
meson setup --backend=%backend% --buildtype=%meson_buildtype% ..\..
if %errorlevel% neq 0 exit /b %errorlevel%
if not %backend%==ninja devenv prj1.sln /upgrade
if %errorlevel% neq 0 exit /b %errorlevel%
