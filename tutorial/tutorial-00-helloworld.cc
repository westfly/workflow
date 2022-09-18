#include <stdio.h>
#include "workflow/WFHttpServer.h"

int main()
{
    WFHttpServer server([](WFHttpTask *task) {
		printf("task_seq %lld\n", task->get_task_seq());
        task->get_resp()->append_output_body("<html>Hello World!</html>");
    });

    if (server.start(8888) == 0) { // start server on port 8888
        getchar(); // press "Enter" to end.
        server.stop();
    }

    return 0;
}

