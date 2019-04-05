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
rmdir /s /q meson-private
meson setup --backend=%backend% --buildtype=%meson_buildtype% ..\..
if %errorlevel% neq 0 exit /b %errorlevel%
if not %backend%==ninja devenv prj1.sln /upgrade
if %errorlevel% neq 0 exit /b %errorlevel%
