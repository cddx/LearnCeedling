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