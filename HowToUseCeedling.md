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
