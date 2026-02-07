#define NOB_IMPLEMENTATION
#define NOB_WARN_DEPRECATED
#include "nob.h"
#include "config.h"
#include "folders.h"

int main(void)
{
    Cmd cmd = {0};
#ifdef FOO
    nob_log(INFO, "FOO feature is enabled");
#endif // FOO
#ifdef BAR
    nob_log(INFO, "BAR feature is enabled");
#endif // BAR
    const char *output_path = BUILD_FOLDER"main";
    const char *input_path = SRC_FOLDER"main.c";
    if (!spec(&cmd,
        .output = output_path,
        .inputs = strs(input_path),
        .default_flags = true,
        .include_dirs = strs(BUILD_FOLDER, "."))) return 1;
    if (!cmd_run(&cmd)) return 1;
    return 0;
}
