!define APPNAME "Basic Numerical Methods"
!define COMPANYNAME "hafsoftdz"
!define DESCRIPTION "A practical tool (for students and engineers) to foresee the result of calculus exercises."
# These three must be integers
!define VERSIONMAJOR 4
!define VERSIONMINOR 5
!define VERSIONBUILD 9
# These will be displayed by the "Click here for support information" link in "Add/Remove Programs"
# It is possible to use "mailto:" links in here to open the email client
!define HELPURL "https://sites.google.com/site/courshaf" # "Support Information" link
!define UPDATEURL "https://sites.google.com/site/courshaf" # "Product Updates" link
!define ABOUTURL "https://sites.google.com/site/courshaf" # "Publisher" link
# This is the size (in kB) of all the files copied into "Program Files"
!define INSTALLSIZE 29276.39


Name "${COMPANYNAME} - ${APPNAME}"
Icon "basic_numerical_methods.ico"

OutFile "basic_numerical_methods_win64_install_4.5.9.exe"

Icon "basic_numerical_methods.ico"
UninstallIcon "basic_numerical_methods.ico"


DirText "Uninstall previous version if exist and Choose directory for installing (Basic Numerical Methods) Ver 4.5.9/29-4-2023"

InstallDir "$PROGRAMFILES\basic_numerical_methods"

Section "Install"
  SetOutPath $INSTDIR
  File "C:\Qt\6.5.0\mingw_64\bin\libgcc_s_seh-1.dll"
  File "C:\Qt\6.5.0\mingw_64\bin\libstdc++-6.dll"
  File "C:\Qt\6.5.0\mingw_64\bin\libwinpthread-1.dll"
  File "C:\Qt\6.5.0\mingw_64\bin\Qt6Core.dll"
  File "C:\Qt\6.5.0\mingw_64\bin\Qt6Gui.dll"
  File "C:\Qt\6.5.0\mingw_64\bin\Qt6PrintSupport.dll"
  File "C:\Qt\6.5.0\mingw_64\bin\Qt6Widgets.dll"
CreateDirectory $INSTDIR\platforms
SetOutPath $INSTDIR\platforms
  File "C:\Qt\6.5.0\mingw_64\plugins\platforms\qwindows.dll"
SetOutPath $INSTDIR 
 File "..\CompilationWin\release\basic_numerical_methods.exe"
 File "basic_numerical_methods.ico"

 # WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\basic_numerical_methods" "DisplayName" "basic_numerical_methods"
#  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\basic_numerical_methods" "UninstallString" "$INSTDIR\uninstall.exe"
 WriteUninstaller "uninstall.exe"



# Registry information for add/remove programs
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "DisplayName" "${APPNAME} - ${DESCRIPTION}"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "UninstallString" "$\"$INSTDIR\uninstall.exe$\""
	#WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "QuietUninstallString" "$\"$INSTDIR\uninstall.exe$\" /S"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "InstallLocation" "$\"$INSTDIR$\""
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "DisplayIcon" "$\"$INSTDIR\basic_numerical_methods.ico$\""
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "Publisher" "${COMPANYNAME}"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "HelpLink" "$\"${HELPURL}$\""
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "URLUpdateInfo" "$\"${UPDATEURL}$\""
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "URLInfoAbout" "$\"${ABOUTURL}$\""
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "DisplayVersion" "${VERSIONMAJOR}.${VERSIONMINOR}.${VERSIONBUILD}"
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "VersionMajor" ${VERSIONMAJOR}
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "VersionMinor" ${VERSIONMINOR}
	# There is no option for modifying or repairing the install
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "NoModify" 1
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "NoRepair" 1
	# Set the INSTALLSIZE constant (!defined at the top of this script) so Add/Remove Programs can accurately report the size
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}" "EstimatedSize" ${INSTALLSIZE}

SectionEnd

Section "Shortcuts"
  SetShellVarContext all
  CreateDirectory "$SMPROGRAMS\basic_numerical_methods"
  SetOutPath $INSTDIR
  CreateShortCut "$SMPROGRAMS\basic_numerical_methods\basic_numerical_methods.lnk""$INSTDIR\basic_numerical_methods.exe" "" "$INSTDIR\basic_numerical_methods.ico"
  SetOutPath $INSTDIR
  CreateShortCut "$DESKTOP\basic_numerical_methods.lnk""$INSTDIR\basic_numerical_methods.exe"
  CreateShortCut "$QUICKLAUNCH\basic_numerical_methods.lnk""$INSTDIR\basic_numerical_methods.exe"
  CreateShortCut "$SMPROGRAMS\basic_numerical_methods\uninstall_basic_numerical_methods.lnk""$INSTDIR\uninstall.exe"
SectionEnd

UninstallText "Close basic_numerical_methods if running ; This will uninstall 'Basic Numerical Methods' from your system"

Section "Uninstall"
SetShellVarContext all
#DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\basic_numerical_methods"
DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${COMPANYNAME} ${APPNAME}"
Delete "$SMPROGRAMS\basic_numerical_methods\basic_numerical_methods.lnk"
Delete "$SMPROGRAMS\basic_numerical_methods\uninstall_basic_numerical_methods.lnk"
RmDir "$SMPROGRAMS\basic_numerical_methods"
Delete "$DESKTOP\basic_numerical_methods.lnk"
Delete "$QUICKLAUNCH\basic_numerical_methods.lnk"
Delete "$INSTDIR\libgcc_s_seh-1.dll"
Delete "$INSTDIR\libstdc++-6.dll"
Delete "$INSTDIR\libwinpthread-1.dll"
Delete "$INSTDIR\Qt6Core.dll"
Delete "$INSTDIR\Qt6Gui.dll"
Delete "$INSTDIR\Qt6PrintSupport.dll"
Delete "$INSTDIR\Qt6Widgets.dll"
Delete "$INSTDIR\platforms\qwindows.dll"
RMDir $INSTDIR\platforms
Delete "$INSTDIR\basic_numerical_methods.exe"
Delete "$INSTDIR\basic_numerical_methods.ico"
Delete "$INSTDIR\uninstall.exe"
RmDir "$INSTDIR"
SectionEnd
