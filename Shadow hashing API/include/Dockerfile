FROM ubuntu:18.04 AS builder
RUN apt-get update -yqq && \
apt-get install -yqq cmake git uuid-dev gcc g++ autoconf
ENV ASIO=/asio
ENV ASIO_INTERNAL=/asio/asio
ENV CINATRA=/cinatra
ENV CINATRA_EXAMPLE=/cinatra/example
WORKDIR /
RUN git clone https://github.com/chriskohlhoff/asio.git
WORKDIR $ASIO
RUN git checkout 8087252a0c3c2f0baad96ddbd6554db17a846376
WORKDIR $ASIO_INTERNAL
RUN ./autogen.sh && ./configure 
RUN make && make install
WORKDIR /
RUN git clone https://github.com/qicosmos/cinatra.git
WORKDIR $CINATRA
RUN git checkout 5acb35cd72c3f72512c0a55e7dea9e25d7779039
WORKDIR /asio/asio
RUN ./autogen.sh && ./configure 
WORKDIR $CINATRA_EXAMPLE
COPY main.cpp crixus.h crixus2.h anti.h echo.h Locate.h SHA_256.h sha256.h un_echo.h functions.h ./
RUN mkdir build && cd build && cmake .. && make

FROM ubuntu:18.04
WORKDIR /root/
COPY --from=builder cinatra/example/build/cinatra_example .
EXPOSE 8090
CMD ./cinatra_example