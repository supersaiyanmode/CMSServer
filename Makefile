#Below variable declarations will be maintained in all future Makefiles generated
LIBS=-lpthread
CPPCOMPILER=g++
CCOMPILER=gcc
COMPILEFLAGS=-Wall -g -O3
DEFINES=THREAD_POOL_TCP_SERVER_UNIT_TEST

#Do not make any changes below!!
PREPROCESSORDEFINES=$(patsubst %,-D%,$(DEFINES))
UNITS=obj/Util/Server/BaseTCPServer.o obj/Util/Server/RequestProcessors/ForkingRequestProcessor.o obj/Util/Server/RequestProcessors/ThreadingRequestProcessor.o obj/Util/Server/RequestProcessors/ThreadPoolRequestProcessor.o obj/Util/Server/ThreadingTCPServer.o obj/Util/Server/ThreadPoolTCPServer.o obj/Util/Server/ServerSkeleton.o obj/Util/Server/test/ThreadPoolTCPServerTest.o obj/Util/Server/test/ThreadingTCPServerTest.o obj/Util/Time/TimeSpan.o obj/Util/IO/SocketIO/TCPClientSocket.o obj/Util/IO/SocketIO/Connection.o obj/Util/IO/SocketIO/SocketException.o obj/Util/IO/SocketIO/Socket.o obj/Util/IO/SocketIO/TCPSocket.o obj/Util/IO/SocketIO/TCPServerSocket.o obj/Util/IO/main.o obj/Util/IO/Structure/Line/LineWriter.o obj/Util/IO/Structure/Line/LineReader.o obj/Util/Thread/Condition.o obj/Util/Thread/Thread.o obj/Util/Thread/ThreadPool.o obj/Util/Thread/ThreadLogger.o obj/Util/Thread/Mutex.o obj/Util/Thread/test/prodcons.o obj/Util/Thread/test/ThreadTest.o obj/Util/Thread/test/ThreadPoolTest.o obj/main.o obj/Protocol/CMSHeaderDefinition.o

all : $(UNITS)
	$(CPPCOMPILER) $(COMPILEFLAGS) $(UNITS) $(LIBS)
obj/Util/Server/BaseTCPServer.o : Util/Server/BaseTCPServer.cpp Util/Server/BaseTCPServer.h Util/Server/ServerSkeleton.h Util/IO/SocketIO/TCPServerSocket.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/Connection.h Util/Server/RequestProcessors/RequestProcessor.h Util/IO/SocketIO/Connection.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h
	@mkdir -p obj/Util/Server
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/BaseTCPServer.cpp -o obj/Util/Server/BaseTCPServer.o

obj/Util/Server/RequestProcessors/ForkingRequestProcessor.o : Util/Server/RequestProcessors/ForkingRequestProcessor.cpp 
	@mkdir -p obj/Util/Server/RequestProcessors
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/RequestProcessors/ForkingRequestProcessor.cpp -o obj/Util/Server/RequestProcessors/ForkingRequestProcessor.o

obj/Util/Server/RequestProcessors/ThreadingRequestProcessor.o : Util/Server/RequestProcessors/ThreadingRequestProcessor.cpp Util/Server/RequestProcessors/ThreadingRequestProcessor.h Util/Server/RequestProcessors/RequestProcessor.h Util/IO/SocketIO/Connection.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/Thread/Thread.h
	@mkdir -p obj/Util/Server/RequestProcessors
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/RequestProcessors/ThreadingRequestProcessor.cpp -o obj/Util/Server/RequestProcessors/ThreadingRequestProcessor.o

obj/Util/Server/RequestProcessors/ThreadPoolRequestProcessor.o : Util/Server/RequestProcessors/ThreadPoolRequestProcessor.cpp Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h Util/Server/RequestProcessors/RequestProcessor.h Util/IO/SocketIO/Connection.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/Thread/Thread.h Util/Thread/ThreadPool.h Util/Thread/ThreadLogger.h Util/Thread/SynchronisedQueue.h Util/Thread/Mutex.h Util/Thread/Condition.h Util/Time/TimeSpan.h
	@mkdir -p obj/Util/Server/RequestProcessors
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/RequestProcessors/ThreadPoolRequestProcessor.cpp -o obj/Util/Server/RequestProcessors/ThreadPoolRequestProcessor.o

obj/Util/Server/ThreadingTCPServer.o : Util/Server/ThreadingTCPServer.cpp Util/Server/ThreadingTCPServer.h Util/Server/BaseTCPServer.h Util/Server/ServerSkeleton.h Util/IO/SocketIO/TCPServerSocket.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/Connection.h Util/Server/RequestProcessors/RequestProcessor.h Util/IO/SocketIO/Connection.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/Server/RequestProcessors/ThreadingRequestProcessor.h Util/Thread/Thread.h
	@mkdir -p obj/Util/Server
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/ThreadingTCPServer.cpp -o obj/Util/Server/ThreadingTCPServer.o

obj/Util/Server/ThreadPoolTCPServer.o : Util/Server/ThreadPoolTCPServer.cpp Util/Server/ThreadPoolTCPServer.h Util/Server/BaseTCPServer.h Util/Server/ServerSkeleton.h Util/IO/SocketIO/TCPServerSocket.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/Connection.h Util/Server/RequestProcessors/RequestProcessor.h Util/IO/SocketIO/Connection.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h Util/Thread/Thread.h Util/Thread/ThreadPool.h Util/Thread/ThreadLogger.h Util/Thread/SynchronisedQueue.h Util/Thread/Mutex.h Util/Thread/Condition.h Util/Time/TimeSpan.h
	@mkdir -p obj/Util/Server
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/ThreadPoolTCPServer.cpp -o obj/Util/Server/ThreadPoolTCPServer.o

obj/Util/Server/ServerSkeleton.o : Util/Server/ServerSkeleton.cpp Util/Server/ServerSkeleton.h Util/IO/SocketIO/TCPServerSocket.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/Connection.h
	@mkdir -p obj/Util/Server
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/ServerSkeleton.cpp -o obj/Util/Server/ServerSkeleton.o

obj/Util/Server/test/ThreadPoolTCPServerTest.o : Util/Server/test/ThreadPoolTCPServerTest.cpp Util/Server/ThreadPoolTCPServer.h Util/Server/BaseTCPServer.h Util/Server/ServerSkeleton.h Util/IO/SocketIO/TCPServerSocket.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/Connection.h Util/Server/RequestProcessors/RequestProcessor.h Util/IO/SocketIO/Connection.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h Util/Thread/Thread.h Util/Thread/ThreadPool.h Util/Thread/ThreadLogger.h Util/Thread/SynchronisedQueue.h Util/Thread/Mutex.h Util/Thread/Condition.h Util/Time/TimeSpan.h Util/IO/Structure/Line/LineReader.h Util/IO/InputOutputCapable.h Util/IO/Structure/Line/LineWriter.h Util/IO/SocketIO/TCPClientSocket.h Util/Thread/Mutex.h Util/Thread/ThreadLogger.h
	@mkdir -p obj/Util/Server/test
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/test/ThreadPoolTCPServerTest.cpp -o obj/Util/Server/test/ThreadPoolTCPServerTest.o

obj/Util/Server/test/ThreadingTCPServerTest.o : Util/Server/test/ThreadingTCPServerTest.cpp Util/Server/ThreadingTCPServer.h Util/Server/BaseTCPServer.h Util/Server/ServerSkeleton.h Util/IO/SocketIO/TCPServerSocket.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/Connection.h Util/Server/RequestProcessors/RequestProcessor.h Util/IO/SocketIO/Connection.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/Server/RequestProcessors/ThreadingRequestProcessor.h Util/Thread/Thread.h Util/IO/Structure/Line/LineReader.h Util/IO/InputOutputCapable.h Util/IO/Structure/Line/LineWriter.h Util/IO/SocketIO/TCPClientSocket.h Util/Thread/Mutex.h Util/Thread/ThreadLogger.h
	@mkdir -p obj/Util/Server/test
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/test/ThreadingTCPServerTest.cpp -o obj/Util/Server/test/ThreadingTCPServerTest.o

obj/Util/Time/TimeSpan.o : Util/Time/TimeSpan.cpp Util/Time/TimeSpan.h
	@mkdir -p obj/Util/Time
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Time/TimeSpan.cpp -o obj/Util/Time/TimeSpan.o

obj/Util/IO/SocketIO/TCPClientSocket.o : Util/IO/SocketIO/TCPClientSocket.cpp Util/IO/SocketIO/TCPClientSocket.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/SocketIO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/SocketIO/TCPClientSocket.cpp -o obj/Util/IO/SocketIO/TCPClientSocket.o

obj/Util/IO/SocketIO/Connection.o : Util/IO/SocketIO/Connection.cpp Util/IO/SocketIO/Connection.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/IO/SocketIO/TCPServerSocket.h Util/IO/SocketIO/TCPClientSocket.h
	@mkdir -p obj/Util/IO/SocketIO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/SocketIO/Connection.cpp -o obj/Util/IO/SocketIO/Connection.o

obj/Util/IO/SocketIO/SocketException.o : Util/IO/SocketIO/SocketException.cpp Util/IO/SocketIO/SocketException.h
	@mkdir -p obj/Util/IO/SocketIO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/SocketIO/SocketException.cpp -o obj/Util/IO/SocketIO/SocketException.o

obj/Util/IO/SocketIO/Socket.o : Util/IO/SocketIO/Socket.cpp Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/SocketIO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/SocketIO/Socket.cpp -o obj/Util/IO/SocketIO/Socket.o

obj/Util/IO/SocketIO/TCPSocket.o : Util/IO/SocketIO/TCPSocket.cpp Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/SocketIO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/SocketIO/TCPSocket.cpp -o obj/Util/IO/SocketIO/TCPSocket.o

obj/Util/IO/SocketIO/TCPServerSocket.o : Util/IO/SocketIO/TCPServerSocket.cpp Util/IO/SocketIO/TCPServerSocket.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/Connection.h
	@mkdir -p obj/Util/IO/SocketIO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/SocketIO/TCPServerSocket.cpp -o obj/Util/IO/SocketIO/TCPServerSocket.o

obj/Util/IO/main.o : Util/IO/main.cpp Util/IO/Structure/Line/LineReader.h Util/IO/InputOutputCapable.h Util/IO/Structure/Line/LineWriter.h Util/IO/SocketIO/TCPServerSocket.h Util/IO/SocketIO/TCPSocket.h Util/IO/SocketIO/Socket.h Util/IO/SocketIO/SocketException.h Util/IO/InputOutputCapable.h Util/IO/SocketIO/Connection.h Util/IO/SocketIO/TCPClientSocket.h
	@mkdir -p obj/Util/IO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/main.cpp -o obj/Util/IO/main.o

obj/Util/IO/Structure/Line/LineWriter.o : Util/IO/Structure/Line/LineWriter.cpp Util/IO/Structure/Line/LineWriter.h Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/Structure/Line
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/Structure/Line/LineWriter.cpp -o obj/Util/IO/Structure/Line/LineWriter.o

obj/Util/IO/Structure/Line/LineReader.o : Util/IO/Structure/Line/LineReader.cpp Util/IO/Structure/Line/LineReader.h Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/Structure/Line
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/Structure/Line/LineReader.cpp -o obj/Util/IO/Structure/Line/LineReader.o

obj/Util/Thread/Condition.o : Util/Thread/Condition.cpp Util/Thread/Condition.h Util/Thread/Mutex.h Util/Time/TimeSpan.h
	@mkdir -p obj/Util/Thread
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/Condition.cpp -o obj/Util/Thread/Condition.o

obj/Util/Thread/Thread.o : Util/Thread/Thread.cpp Util/Thread/Thread.h
	@mkdir -p obj/Util/Thread
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/Thread.cpp -o obj/Util/Thread/Thread.o

obj/Util/Thread/ThreadPool.o : Util/Thread/ThreadPool.cpp 
	@mkdir -p obj/Util/Thread
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/ThreadPool.cpp -o obj/Util/Thread/ThreadPool.o

obj/Util/Thread/ThreadLogger.o : Util/Thread/ThreadLogger.cpp Util/Thread/ThreadLogger.h Util/Thread/Mutex.h
	@mkdir -p obj/Util/Thread
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/ThreadLogger.cpp -o obj/Util/Thread/ThreadLogger.o

obj/Util/Thread/Mutex.o : Util/Thread/Mutex.cpp Util/Thread/Mutex.h
	@mkdir -p obj/Util/Thread
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/Mutex.cpp -o obj/Util/Thread/Mutex.o

obj/Util/Thread/test/prodcons.o : Util/Thread/test/prodcons.cpp Util/Thread/Thread.h Util/Thread/ThreadLogger.h Util/Thread/SynchronisedQueue.h Util/Thread/Mutex.h Util/Thread/Condition.h Util/Time/TimeSpan.h
	@mkdir -p obj/Util/Thread/test
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/test/prodcons.cpp -o obj/Util/Thread/test/prodcons.o

obj/Util/Thread/test/ThreadTest.o : Util/Thread/test/ThreadTest.cpp Util/Thread/Thread.h Util/Thread/Mutex.h Util/Thread/ThreadLogger.h
	@mkdir -p obj/Util/Thread/test
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/test/ThreadTest.cpp -o obj/Util/Thread/test/ThreadTest.o

obj/Util/Thread/test/ThreadPoolTest.o : Util/Thread/test/ThreadPoolTest.cpp Util/Thread/ThreadPool.h Util/Thread/Thread.h Util/Thread/ThreadLogger.h Util/Thread/SynchronisedQueue.h Util/Thread/Mutex.h Util/Thread/Condition.h Util/Time/TimeSpan.h
	@mkdir -p obj/Util/Thread/test
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/test/ThreadPoolTest.cpp -o obj/Util/Thread/test/ThreadPoolTest.o

obj/main.o : main.cpp 
	@mkdir -p obj
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c main.cpp -o obj/main.o

obj/Protocol/CMSHeaderDefinition.o : Protocol/CMSHeaderDefinition.cpp Protocol/CMSHeaderDefinition.h Util/Serialisable.h Util/BaseFunctor.h
	@mkdir -p obj/Protocol
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Protocol/CMSHeaderDefinition.cpp -o obj/Protocol/CMSHeaderDefinition.o

clean:
	@rm -rf obj
	@echo Cleaned!
