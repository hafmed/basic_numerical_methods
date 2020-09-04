Name "basic_numerical_methods HAFIANE Mohamed"
OutFile "basic_numerical_methods_win64_install_1.9.0.exe"

Icon "basic_numerical_methods.ico"
UninstallIcon "basic_numerical_methods.ico"


DirText "Uninstall previous version if exist and Choose directory for installing (basic_numerical_methods) Ver 1.9.0 du 2-9-2020"

InstallDir "$PROGRAMFILES\basic_numerical_methods"

Section "Install"
  SetOutPath $INSTDIR
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\libgcc_s_seh-1.dll"
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\libstdc++-6.dll"
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\libwinpthread-1.dll"
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5Core.dll"
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5Gui.dll"
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5PrintSupport.dll"
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5Widgets.dll"
CreateDirectory $INSTDIR\platforms
SetOutPath $INSTDIR\platforms
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\plugins\platforms\qwindows.dll"
SetOutPath $INSTDIR 
 File "..\CompilationWin\release\basic_numerical_methods.exe"
 File "basic_numerical_methods.ico"

  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\basic_numerical_methods" "DisplayName" "basic_numerical_methods"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\basic_numerical_methods" "UninstallString" "$INSTDIR\uninstall.exe"
  WriteUninstaller "uninstall.exe"
SectionEnd

Section "Shortcuts"
  CreateDirectory "$SMPROGRAMS\basic_numerical_methods"
  SetOutPath $INSTDIR
  CreateShortCut "$SMPROGRAMS\basic_numerical_methods\basic_numerical_methods.lnk""$INSTDIR\basic_numerical_methods.exe"
  SetOutPath $INSTDIR
  CreateShortCut "$DESKTOP\basic_numerical_methods.lnk""$INSTDIR\basic_numerical_methods.exe"
  CreateShortCut "$QUICKLAUNCH\basic_numerical_methods.lnk""$INSTDIR\basic_numerical_methods.exe"
  CreateShortCut "$SMPROGRAMS\basic_numerical_methods\uninstall_basic_numerical_methods.lnk""$INSTDIR\uninstall.exe"
SectionEnd

UninstallText "Close basic_numerical_methods if running ; This will uninstall basic_numerical_methods from your system"

Section "Uninstall"
DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\basic_numerical_methods"
Delete "$SMPROGRAMS\basic_numerical_methods\basic_numerical_methods.lnk"
Delete "$SMPROGRAMS\basic_numerical_methods\uninstall_basic_numerical_methods.lnk"
RmDir "$SMPROGRAMS\basic_numerical_methods"
Delete "$DESKTOP\basic_numerical_methods.lnk"
Delete "$QUICKLAUNCH\basic_numerical_methods.lnk"
Delete "$INSTDIR\libgcc_s_seh-1.dll"
Delete "$INSTDIR\libstdc++-6.dll"
Delete "$INSTDIR\libwinpthread-1.dll"
Delete "$INSTDIR\Qt5Core.dll"
Delete "$INSTDIR\Qt5Gui.dll"
Delete "$INSTDIR\Qt5PrintSupport.dll"
Delete "$INSTDIR\Qt5Widgets.dll"
Delete "$INSTDIR\platforms\qwindows.dll"
RMDir $INSTDIR\platforms
Delete "$INSTDIR\basic_numerical_methods.exe"
Delete "$INSTDIR\basic_numerical_methods.ico"
Delete "$INSTDIR\uninstall.exe"
RmDir "$INSTDIR"
SectionEnd