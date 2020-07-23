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
        // For more information, visit: https://go.microsoft.ccom/fwlink/?linkid=830387
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
    2 ceedling utils:gcov 或者 ceedling gcov:all utils:gcov
    3 ceedling clobber # 请除所以生成的文件
    4 cmock array 的mock 函数要用uint8_t 不能用char
    5 使用1可以产生unit test的所以代码覆盖率，再用2查看html报告，确认test case 程序路径的覆盖率


# LearnCeedling

ceedling new YourNewProjectName

ceedling new --docs MyAwesomeProject

ceedling new --local YourNewProjectName

ceedling upgrade --local YourNewProjectName

ceedling upgrade --local --no_configs YoureNewProject

ceedling new --gitignore YourNewProject

ceedling new --docs --local --gitignore YoureNewProject

# How to generate code coverage html report
    ceedling gcov:all
    ceedling utils:gcov
    ceedling gcov:all utils:gcov


# project.yml

    :plugins:
    :load_paths:
        - vendor/ceedling/plugins
    :enabled:
        - stdout_pretty_tests_report
        - module_generator
        - raw_output_report
        - xml_tests_report
        - gcov


请参考CeelingPacket.md，这是最新说明文件，
而其它的说明文件过时或有错误！！！！！！！！！！！！！！！！！！

里面有关于module_generator 的Boilerplate 和Naming说明 

    :module_generator:
    :boileplate_files:
    :src: '/* this is a source file */'
    :inc: '/* this is a include file */'
    :tst: '/* this is a test file */'

or 

    :module_generator:
    :boileplate_files:
    :src: |
        // line 1
        //  line 2
    

naming: caps   caps前面没有：！！！！！！！！！！！！！
