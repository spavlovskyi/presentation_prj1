pip3 install --upgrade conan meson ninja conan
if %errorlevel% neq 0 exit /b %errorlevel%
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
conan remote add -f -i 0 presentation_artifactory http://localhost:8082/artifactory/api/conan/conan-local
if %errorlevel% neq 0 exit /b %errorlevel%
