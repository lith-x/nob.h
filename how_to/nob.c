// Makes sure the examples are buildable. Used usually on CI.
#include "../shared.h"

const char *examples[] = {
    "001_basic_usage",
    "005_parallel_build",
    "010_nob_two_stage",
};

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    Cmd cmd = {0};

    for (size_t i = 0; i < ARRAY_LEN(examples); ++i) {
        const char *example = examples[i];
        nob_log(INFO, "--- %s ---", example);
        size_t mark = temp_save();
            if (!set_current_dir(temp_sprintf("./%s", example))) return 1;
                if (!spec(&cmd, .output = "./nob", .inputs = strs("nob.c"), .default_flags = true)) return 1;
                if (!cmd_run(&cmd)) return 1;

                cmd_append(&cmd, "./nob");
                if (!cmd_run(&cmd)) return 1;
            if (!set_current_dir("..")) return 1;
        temp_rewind(mark);
    }

    return 0;
}
