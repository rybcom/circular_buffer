cd .. 
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" "solution.sln" /t:Build /p:Configuration=debug
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" "solution.sln" /t:Build /p:Configuration=profiler
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" "solution.sln" /t:Build /p:Configuration=release
PAUSE