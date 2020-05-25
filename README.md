# LearnCeedling
project.yml

    :plugins:
    :load_paths:
        - vendor/ceedling/plugins
    :enabled:
        - stdout_pretty_tests_report
        - module_generator
        - raw_output_report
        - xml_tests_report
        - gcov
## launch.json
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
    3 ceedling clobber # 请除所以生成的文件
    4 cmock array 的mock 函数要用uint8_t 不能用char