setlocal
set meson_buildtype=debug
set builddir=out
set backend=vs2017
cd %~dp0
mkdir %builddir%
cd %builddir%
rmdir /s /q meson-private
meson setup --backend=%backend% --buildtype=%meson_buildtype% ..
if %errorlevel% neq 0 exit /b %errorlevel%
if not %backend%==ninja devenv prj1.sln /upgrade
if %errorlevel% neq 0 exit /b %errorlevel%
