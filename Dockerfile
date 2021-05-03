FROM centos:7 AS builder

COPY ./malloc.c .

RUN yum update -y; \
yum install -y gcc; \
gcc -o malloc malloc.c

FROM centos:7
COPY --from=builder /malloc .
