# LearnCeedling

## lauch.json
    {
        // Use IntelliSense to learn about possible attributes.
        // Hover to view descriptions of existing attributes.
        // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
        "version": "0.2.0",
        "configurations": [
            {
                "name": "ceedling_gdb",
                "type": "cppdbg",
                "request": "launch",
                "program": "${workspaceFolder}/build/test/out/${command:ceedlingExplorer.debugTestExecutable}",
                "args": [],
                "stopAtEntry": false,
                "cwd": "${workspaceFolder}",
                "environment": [],
                "externalConsole": false,
                "MIMode": "gdb",
                "miDebuggerPath": "C:/mingw64/bin/gdb.exe",
                "setupCommands": [
                    {
                        "description": "Enable pretty-printing for gdb",
                        "text": "-enable-pretty-printing",
                        "ignoreFailures": true
                    }
                ]
            }
        ]
    }


How To Generate Html Report
----------------------------
    1 ceedling gcov:all 
    2 ceedling utils:gcov 