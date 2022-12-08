
set solution_dir=%~1
set target_dir=%~2

CD %target_dir%
MKDIR rsc
CD rsc
XCOPY /e /v /y "%solution_dir%rsc\"  "%target_dir%rsc\"
