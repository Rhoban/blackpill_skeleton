from os import path
import sys
import mbedignore

Import("env")

root_dir = env['PROJECT_DIR']

sys.path.append(path.join(root_dir, 'scripts'))

mbedignore_path = path.join(root_dir, '.mbedignore')
mbed_os_dir = env['PROJECT_CORE_DIR'] + '/packages/framework-mbed'

print("\nMBED_OS_DIR:" + mbed_os_dir)

# Does the job related to ignoring the paths.
mbedignore.apply(mbedignore_path, mbed_os_dir)
