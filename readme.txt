
### Project Setting

[Include directory]
..\_library\SDL2\include;..\_library\SDL2_image\include;$(IncludePath)

[Lib directory]
..\_library\SDL2\lib\x64;..\_library\SDL2_image\lib\x64;$(LibraryPath)

[Dependency]
SDL2.lib;SDL2main.lib;SDL2_image.lib;

[DLL]
copy SDL2.dll, SDL2_image.dll to [project\x64\Debug]



### Git 작업 절차

1. 작업 전, 브랜치를 새로 만든다.
git checkout -b 브랜치이름

2. 작업 후, 스테이징할 파일을 확인하고 add, commit 한다.
git status
git add .
git commit -m "커밋 코맨트"

3. 서버에 업로드할 준비가 완료되면 push 한다.
git push --set-upstream origin 브랜치이름

4. 서버에서 Pull Request 하고, Merge 한다.

5. main 브랜치로 돌아가서, 서버의 최신본을 pull 한다.
git checkout main
git pull

