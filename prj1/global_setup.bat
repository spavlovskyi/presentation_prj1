pip3 install --upgrade conan meson ninja conan
if %errorlevel% neq 0 exit /b %errorlevel%
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
