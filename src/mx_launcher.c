#include "ush.h"

void mx_launcher(st_launch *l_inf, t_shell *shell) {
    pid_t child_pid;
    pid_t wpid;
    int status;
    int shell_is_interactive = isatty(STDIN_FILENO);

    l_inf->pgid = 0;
    if (l_inf->type == 1)
        mx_launch_builtin(l_inf, shell);

    else if (l_inf->type == 2) {
        child_pid = fork();
        if (child_pid < 0) {
            mx_printerr("u$h: error forking\n");
            exit(1);
        }
        else if (child_pid == 0) {
            if (shell_is_interactive) {
                if (l_inf->pgid == 0)
                    l_inf->pgid = child_pid;
                setpgid(child_pid, l_inf->pgid);
                tcsetpgrp(STDIN_FILENO, getpid());
                signal(SIGINT, MX_SIG_DFL);
                signal(SIGQUIT, MX_SIG_DFL);
                signal(SIGTSTP, MX_SIG_DFL);
                signal(SIGTTIN, MX_SIG_DFL);
                signal(SIGTTOU, MX_SIG_DFL);
                signal(SIGCHLD, SIG_DFL);
            }
            if (execvp(l_inf->filepath, l_inf->cmd_arr) < 0) {
                perror("ush mx_launch_binary: 51");
                _exit(shell->status);
            }
        }
        else {
            if (shell_is_interactive) {
                if (l_inf->pgid == 0)
                    l_inf->pgid = child_pid;
                setpgid(child_pid, 0);
            }
            tcsetpgrp(STDIN_FILENO, l_inf->pgid);
            signal(SIGTTOU, MX_SIG_IGN);
            wpid = waitpid(child_pid, &status, MX_WUNTRACED);
            while(!WIFEXITED(status) && !MX_WIFSTOPP(status))
                wpid = waitpid(child_pid, &status, MX_WUNTRACED);
            shell->status = WEXITSTATUS(status);
            shell->status_exec = shell->status;
            tcsetpgrp(STDIN_FILENO, getpid());
        }
    }
}
