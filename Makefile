#Below variable declarations will be maintained in all future Makefiles generated
LIBS=-lpthread
CPPCOMPILER=g++
CCOMPILER=gcc
COMPILEFLAGS=-Wall -pg -O3
DEFINES=MGMT_TEST

#Do not make any changes below!!
PREPROCESSORDEFINES=$(patsubst %,-D%,$(DEFINES))
UNITS= \
		obj/Client/CMSClient.o\
		obj/Client/CMSServerConnection.o\
		obj/Client/QueueReceiver.o\
		obj/Client/QueueSender.o\
		obj/Client/TopicPublisher.o\
		obj/Client/TopicSubscriber.o\
		obj/main.o\
		obj/Protocol/CMSDestination/CMSDestGroup.o\
		obj/Protocol/CMSDestination/CMSDestination.o\
		obj/Protocol/CMSMessage/GenericCMSMessage.o\
		obj/Protocol/CMSMessage/Header/CMSHeaderSet.o\
		obj/Protocol/Exception/ProtocolException.o\
		obj/Server/CMSServer.o\
		obj/Server/Core/BridgeProcessor.o\
		obj/Server/Core/ClientEndPoint.o\
		obj/Server/Core/ClientHandler.o\
		obj/Server/Core/MessageProcessor.o\
		obj/Util/DataType/BaseDataType.o\
		obj/Util/DataType/Primitive/Float.o\
		obj/Util/DataType/Primitive/Number.o\
		obj/Util/DataType/Primitive/String.o\
		obj/Util/IO/InputOutputCapable.o\
		obj/Util/IO/main.o\
		obj/Util/IO/SocketIO/Connection.o\
		obj/Util/IO/SocketIO/Socket.o\
		obj/Util/IO/SocketIO/SocketException.o\
		obj/Util/IO/SocketIO/TCPClientSocket.o\
		obj/Util/IO/SocketIO/TCPServerSocket.o\
		obj/Util/IO/SocketIO/TCPSocket.o\
		obj/Util/IO/Structure/Block/BlockReader.o\
		obj/Util/IO/Structure/Block/BlockWriter.o\
		obj/Util/IO/Structure/Line/LineReader.o\
		obj/Util/IO/Structure/Line/LineWriter.o\
		obj/Util/Management/HTTPEndPointHandlers/PointsHandler.o\
		obj/Util/Management/HTTPEndPointHandlers/PointsListerHandler.o\
		obj/Util/Management/HTTPEndPointHandlers/StaticPageHandler.o\
		obj/Util/Management/main.o\
		obj/Util/Management/ManageableObject.o\
		obj/Util/Management/ManageableObjectParameter.o\
		obj/Util/Management/ManagementServer.o\
		obj/Util/ObjectStore/Exception/ObjectStoreException.o\
		obj/Util/OptParse/OptParse.o\
		obj/Util/Random/Sequential.o\
		obj/Util/Server/BaseTCPServer.o\
		obj/Util/Server/HTTP/HTTPEndPointHandler.o\
		obj/Util/Server/HTTP/HTTPParser.o\
		obj/Util/Server/HTTP/HTTPServerBase.o\
		obj/Util/Server/HTTP/protocol/HTTPRequest.o\
		obj/Util/Server/HTTP/protocol/HTTPResponse.o\
		obj/Util/Server/HTTP/ThreadPoolHTTPServer.o\
		obj/Util/Server/RequestProcessors/ForkingRequestProcessor.o\
		obj/Util/Server/RequestProcessors/ThreadingRequestProcessor.o\
		obj/Util/Server/RequestProcessors/ThreadPoolRequestProcessor.o\
		obj/Util/Server/ServerSkeleton.o\
		obj/Util/Server/test/ThreadingTCPServerTest.o\
		obj/Util/Server/test/ThreadPoolHTTPServerTest.o\
		obj/Util/Server/test/ThreadPoolTCPServerTest.o\
		obj/Util/Server/ThreadingTCPServer.o\
		obj/Util/Server/ThreadPoolTCPServer.o\
		obj/Util/String/StringUtils.o\
		obj/Util/String/test/main.o\
		obj/Util/Thread/Condition.o\
		obj/Util/Thread/Mutex.o\
		obj/Util/Thread/ReadWriteLock.o\
		obj/Util/Thread/test/prodcons.o\
		obj/Util/Thread/test/ThreadPoolTest.o\
		obj/Util/Thread/test/ThreadTest.o\
		obj/Util/Thread/Thread.o\
		obj/Util/Thread/ThreadLogger.o\
		obj/Util/Thread/ThreadPool.o\
		obj/Util/Time/Time.o

all : $(UNITS)
	$(CPPCOMPILER) $(COMPILEFLAGS) $(UNITS) $(LIBS)
obj/Client/CMSClient.o : Client/CMSClient.cpp  \
		Client/CMSClient.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h \
		Util/Random/Sequential.h
	@mkdir -p obj/Client
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Client/CMSClient.cpp -o obj/Client/CMSClient.o

obj/Client/CMSServerConnection.o : Client/CMSServerConnection.cpp  \
		Client/CMSServerConnection.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Thread/Thread.h \
		Util/Thread/Mutex.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Random/Sequential.h \
		Client/CMSClient.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h
	@mkdir -p obj/Client
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Client/CMSServerConnection.cpp -o obj/Client/CMSServerConnection.o

obj/Client/QueueReceiver.o : Client/QueueReceiver.cpp  \
		Client/QueueReceiver.h \
		Client/CMSClient.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h \
		Util/Random/Sequential.h \
		Client/CMSServerConnection.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Thread/Thread.h \
		Util/Thread/Mutex.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h
	@mkdir -p obj/Client
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Client/QueueReceiver.cpp -o obj/Client/QueueReceiver.o

obj/Client/QueueSender.o : Client/QueueSender.cpp  \
		Client/QueueSender.h \
		Client/CMSServerConnection.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Thread/Thread.h \
		Util/Thread/Mutex.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Random/Sequential.h \
		Client/CMSClient.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestination.h
	@mkdir -p obj/Client
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Client/QueueSender.cpp -o obj/Client/QueueSender.o

obj/Client/TopicPublisher.o : Client/TopicPublisher.cpp  \
		Client/TopicPublisher.h \
		Client/CMSServerConnection.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Thread/Thread.h \
		Util/Thread/Mutex.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Random/Sequential.h \
		Client/CMSClient.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestination.h
	@mkdir -p obj/Client
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Client/TopicPublisher.cpp -o obj/Client/TopicPublisher.o

obj/Client/TopicSubscriber.o : Client/TopicSubscriber.cpp  \
		Client/TopicSubscriber.h \
		Client/CMSClient.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h \
		Util/Random/Sequential.h \
		Client/CMSServerConnection.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Thread/Thread.h \
		Util/Thread/Mutex.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h
	@mkdir -p obj/Client
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Client/TopicSubscriber.cpp -o obj/Client/TopicSubscriber.o

obj/main.o : main.cpp  \
		Server/CMSServer.h \
		Server/Core/ClientHandler.h \
		Util/Server/ThreadingTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadingRequestProcessor.h \
		Util/Thread/Thread.h \
		Server/Core/MessageProcessor.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Time/Time.h \
		Server/Core/BridgeProcessor.h \
		Util/Random/Sequential.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Client/QueueReceiver.h \
		Client/CMSClient.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h \
		Util/Random/Sequential.h \
		Client/CMSServerConnection.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Thread/Thread.h \
		Util/Thread/Mutex.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Client/QueueSender.h \
		Protocol/CMSDestination/CMSDestination.h \
		Client/TopicSubscriber.h \
		Client/TopicPublisher.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/Thread.h \
		Util/String/StringUtils.h \
		Util/DataType/Primitive/Number.h \
		Util/DataType/BaseDataType.h \
		Util/Serialisable/Serialisable.h \
		Util/OptParse/OptParse.h
	@mkdir -p obj
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c main.cpp -o obj/main.o

obj/Protocol/CMSDestination/CMSDestGroup.o : Protocol/CMSDestination/CMSDestGroup.cpp  \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/String/StringUtils.h \
		Protocol/Exception/ProtocolException.h
	@mkdir -p obj/Protocol/CMSDestination
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Protocol/CMSDestination/CMSDestGroup.cpp -o obj/Protocol/CMSDestination/CMSDestGroup.o

obj/Protocol/CMSDestination/CMSDestination.o : Protocol/CMSDestination/CMSDestination.cpp  \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/String/StringUtils.h \
		Protocol/Exception/ProtocolException.h
	@mkdir -p obj/Protocol/CMSDestination
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Protocol/CMSDestination/CMSDestination.cpp -o obj/Protocol/CMSDestination/CMSDestination.o

obj/Protocol/CMSMessage/GenericCMSMessage.o : Protocol/CMSMessage/GenericCMSMessage.cpp  \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/IO/Structure/Line/LineReader.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/Structure/Block/BlockReader.h \
		Util/IO/InputOutputCapable.h \
		Util/DataType/Primitive/Number.h \
		Util/DataType/BaseDataType.h \
		Util/Serialisable/Serialisable.h \
		Util/Thread/ThreadLogger.h
	@mkdir -p obj/Protocol/CMSMessage
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Protocol/CMSMessage/GenericCMSMessage.cpp -o obj/Protocol/CMSMessage/GenericCMSMessage.o

obj/Protocol/CMSMessage/Header/CMSHeaderSet.o : Protocol/CMSMessage/Header/CMSHeaderSet.cpp  \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/String/StringUtils.h
	@mkdir -p obj/Protocol/CMSMessage/Header
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Protocol/CMSMessage/Header/CMSHeaderSet.cpp -o obj/Protocol/CMSMessage/Header/CMSHeaderSet.o

obj/Protocol/Exception/ProtocolException.o : Protocol/Exception/ProtocolException.cpp  \
		Protocol/Exception/ProtocolException.h
	@mkdir -p obj/Protocol/Exception
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Protocol/Exception/ProtocolException.cpp -o obj/Protocol/Exception/ProtocolException.o

obj/Server/CMSServer.o : Server/CMSServer.cpp  \
		Server/CMSServer.h \
		Server/Core/ClientHandler.h \
		Util/Server/ThreadingTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadingRequestProcessor.h \
		Util/Thread/Thread.h \
		Server/Core/MessageProcessor.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Time/Time.h \
		Server/Core/BridgeProcessor.h \
		Util/Random/Sequential.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestination.h
	@mkdir -p obj/Server
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Server/CMSServer.cpp -o obj/Server/CMSServer.o

obj/Server/Core/BridgeProcessor.o : Server/Core/BridgeProcessor.cpp  \
		Server/Core/BridgeProcessor.h \
		Util/Random/Sequential.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Server/Core/MessageProcessor.h \
		Util/Time/Time.h
	@mkdir -p obj/Server/Core
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Server/Core/BridgeProcessor.cpp -o obj/Server/Core/BridgeProcessor.o

obj/Server/Core/ClientEndPoint.o : Server/Core/ClientEndPoint.cpp  \
		Server/Core/ClientEndPoint.h \
		Server/Core/MessageProcessor.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Time/Time.h \
		Server/Core/BridgeProcessor.h \
		Util/Random/Sequential.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Thread/Thread.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/ThreadLogger.h
	@mkdir -p obj/Server/Core
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Server/Core/ClientEndPoint.cpp -o obj/Server/Core/ClientEndPoint.o

obj/Server/Core/ClientHandler.o : Server/Core/ClientHandler.cpp  \
		Server/Core/ClientHandler.h \
		Util/Server/ThreadingTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadingRequestProcessor.h \
		Util/Thread/Thread.h \
		Server/Core/MessageProcessor.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Time/Time.h \
		Server/Core/BridgeProcessor.h \
		Util/Random/Sequential.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Thread/ThreadLogger.h \
		Server/Core/ClientEndPoint.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Thread/Thread.h \
		Util/Thread/SynchronisedQueue.h
	@mkdir -p obj/Server/Core
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Server/Core/ClientHandler.cpp -o obj/Server/Core/ClientHandler.o

obj/Server/Core/MessageProcessor.o : Server/Core/MessageProcessor.cpp  \
		Server/Core/MessageProcessor.h \
		Protocol/CMSMessage/GenericCMSMessage.h \
		Protocol/CMSMessage/Header/CMSHeaderSet.h \
		Util/Serialisable/Serialisable.h \
		Util/IO/InputOutputCapable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Time/Time.h \
		Server/Core/ClientEndPoint.h \
		Server/Core/BridgeProcessor.h \
		Util/Random/Sequential.h \
		Protocol/CMSDestination/CMSDestGroup.h \
		Util/Serialisable/Serialisable.h \
		Protocol/CMSDestination/CMSDestination.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Thread/Thread.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/ThreadLogger.h
	@mkdir -p obj/Server/Core
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Server/Core/MessageProcessor.cpp -o obj/Server/Core/MessageProcessor.o

obj/Util/DataType/BaseDataType.o : Util/DataType/BaseDataType.cpp  \
		Util/DataType/BaseDataType.h \
		Util/Serialisable/Serialisable.h
	@mkdir -p obj/Util/DataType
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/DataType/BaseDataType.cpp -o obj/Util/DataType/BaseDataType.o

obj/Util/DataType/Primitive/Float.o : Util/DataType/Primitive/Float.cpp  \
		Util/DataType/Primitive/Float.h \
		Util/DataType/BaseDataType.h \
		Util/Serialisable/Serialisable.h \
		Util/String/StringUtils.h
	@mkdir -p obj/Util/DataType/Primitive
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/DataType/Primitive/Float.cpp -o obj/Util/DataType/Primitive/Float.o

obj/Util/DataType/Primitive/Number.o : Util/DataType/Primitive/Number.cpp  \
		Util/DataType/Primitive/Number.h \
		Util/DataType/BaseDataType.h \
		Util/Serialisable/Serialisable.h \
		Util/String/StringUtils.h
	@mkdir -p obj/Util/DataType/Primitive
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/DataType/Primitive/Number.cpp -o obj/Util/DataType/Primitive/Number.o

obj/Util/DataType/Primitive/String.o : Util/DataType/Primitive/String.cpp  \
		Util/DataType/Primitive/String.h \
		Util/DataType/BaseDataType.h \
		Util/Serialisable/Serialisable.h \
		Util/String/StringUtils.h
	@mkdir -p obj/Util/DataType/Primitive
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/DataType/Primitive/String.cpp -o obj/Util/DataType/Primitive/String.o

obj/Util/IO/InputOutputCapable.o : Util/IO/InputOutputCapable.cpp  \
		Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/InputOutputCapable.cpp -o obj/Util/IO/InputOutputCapable.o

obj/Util/IO/main.o : Util/IO/main.cpp  \
		Util/IO/Structure/Line/LineReader.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/Structure/Line/LineWriter.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/SocketIO/TCPClientSocket.h
	@mkdir -p obj/Util/IO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/main.cpp -o obj/Util/IO/main.o

obj/Util/IO/SocketIO/Connection.o : Util/IO/SocketIO/Connection.cpp  \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPClientSocket.h
	@mkdir -p obj/Util/IO/SocketIO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/SocketIO/Connection.cpp -o obj/Util/IO/SocketIO/Connection.o

obj/Util/IO/SocketIO/Socket.o : Util/IO/SocketIO/Socket.cpp  \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/SocketIO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/SocketIO/Socket.cpp -o obj/Util/IO/SocketIO/Socket.o

obj/Util/IO/SocketIO/SocketException.o : Util/IO/SocketIO/SocketException.cpp  \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/SocketIO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/SocketIO/SocketException.cpp -o obj/Util/IO/SocketIO/SocketException.o

obj/Util/IO/SocketIO/TCPClientSocket.o : Util/IO/SocketIO/TCPClientSocket.cpp  \
		Util/IO/SocketIO/TCPClientSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/SocketIO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/SocketIO/TCPClientSocket.cpp -o obj/Util/IO/SocketIO/TCPClientSocket.o

obj/Util/IO/SocketIO/TCPServerSocket.o : Util/IO/SocketIO/TCPServerSocket.cpp  \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h
	@mkdir -p obj/Util/IO/SocketIO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/SocketIO/TCPServerSocket.cpp -o obj/Util/IO/SocketIO/TCPServerSocket.o

obj/Util/IO/SocketIO/TCPSocket.o : Util/IO/SocketIO/TCPSocket.cpp  \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/SocketIO
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/SocketIO/TCPSocket.cpp -o obj/Util/IO/SocketIO/TCPSocket.o

obj/Util/IO/Structure/Block/BlockReader.o : Util/IO/Structure/Block/BlockReader.cpp  \
		Util/IO/Structure/Block/BlockReader.h \
		Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/Structure/Block
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/Structure/Block/BlockReader.cpp -o obj/Util/IO/Structure/Block/BlockReader.o

obj/Util/IO/Structure/Block/BlockWriter.o : Util/IO/Structure/Block/BlockWriter.cpp  \
		Util/IO/Structure/Block/BlockWriter.h \
		Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/Structure/Block
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/Structure/Block/BlockWriter.cpp -o obj/Util/IO/Structure/Block/BlockWriter.o

obj/Util/IO/Structure/Line/LineReader.o : Util/IO/Structure/Line/LineReader.cpp  \
		Util/IO/Structure/Line/LineReader.h \
		Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/Structure/Line
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/Structure/Line/LineReader.cpp -o obj/Util/IO/Structure/Line/LineReader.o

obj/Util/IO/Structure/Line/LineWriter.o : Util/IO/Structure/Line/LineWriter.cpp  \
		Util/IO/Structure/Line/LineWriter.h \
		Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/IO/Structure/Line
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/IO/Structure/Line/LineWriter.cpp -o obj/Util/IO/Structure/Line/LineWriter.o

obj/Util/Management/HTTPEndPointHandlers/PointsHandler.o : Util/Management/HTTPEndPointHandlers/PointsHandler.cpp  \
		Util/Management/HTTPEndPointHandlers/PointsHandler.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h \
		Util/Management/ManagementServer.h \
		Util/Server/HTTP/ThreadPoolHTTPServer.h \
		Util/Server/ThreadPoolTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h \
		Util/Thread/Thread.h \
		Util/Thread/ThreadPool.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Server/HTTP/HTTPServerBase.h \
		Util/Management/Manageable.h \
		Util/Management/ManageableObjectParameter.h \
		Util/Management/HTTPEndPointHandlers/StaticPageHandler.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h \
		Util/String/StringUtils.h
	@mkdir -p obj/Util/Management/HTTPEndPointHandlers
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Management/HTTPEndPointHandlers/PointsHandler.cpp -o obj/Util/Management/HTTPEndPointHandlers/PointsHandler.o

obj/Util/Management/HTTPEndPointHandlers/PointsListerHandler.o : Util/Management/HTTPEndPointHandlers/PointsListerHandler.cpp  \
		Util/Management/HTTPEndPointHandlers/PointsListerHandler.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h \
		Util/Management/ManagementServer.h \
		Util/Server/HTTP/ThreadPoolHTTPServer.h \
		Util/Server/ThreadPoolTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h \
		Util/Thread/Thread.h \
		Util/Thread/ThreadPool.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Server/HTTP/HTTPServerBase.h \
		Util/Management/Manageable.h \
		Util/Management/ManageableObjectParameter.h \
		Util/Management/HTTPEndPointHandlers/StaticPageHandler.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h
	@mkdir -p obj/Util/Management/HTTPEndPointHandlers
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Management/HTTPEndPointHandlers/PointsListerHandler.cpp -o obj/Util/Management/HTTPEndPointHandlers/PointsListerHandler.o

obj/Util/Management/HTTPEndPointHandlers/StaticPageHandler.o : Util/Management/HTTPEndPointHandlers/StaticPageHandler.cpp  \
		Util/Management/HTTPEndPointHandlers/StaticPageHandler.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h
	@mkdir -p obj/Util/Management/HTTPEndPointHandlers
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Management/HTTPEndPointHandlers/StaticPageHandler.cpp -o obj/Util/Management/HTTPEndPointHandlers/StaticPageHandler.o

obj/Util/Management/main.o : Util/Management/main.cpp  \
		Util/Management/ManageableObject.h \
		Util/Management/Manageable.h \
		Util/Management/ManageableObjectParameter.h \
		Util/Management/ManagementServer.h \
		Util/Server/HTTP/ThreadPoolHTTPServer.h \
		Util/Server/ThreadPoolTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h \
		Util/Thread/Thread.h \
		Util/Thread/ThreadPool.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Server/HTTP/HTTPServerBase.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h \
		Util/Management/HTTPEndPointHandlers/StaticPageHandler.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h \
		Util/String/StringUtils.h \
		Util/Thread/Thread.h \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h
	@mkdir -p obj/Util/Management
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Management/main.cpp -o obj/Util/Management/main.o

obj/Util/Management/ManageableObject.o : Util/Management/ManageableObject.cpp  \
		Util/Management/ManageableObject.h \
		Util/Management/Manageable.h \
		Util/Management/ManageableObjectParameter.h \
		Util/Management/ManagementServer.h \
		Util/Server/HTTP/ThreadPoolHTTPServer.h \
		Util/Server/ThreadPoolTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h \
		Util/Thread/Thread.h \
		Util/Thread/ThreadPool.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Server/HTTP/HTTPServerBase.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h \
		Util/Management/HTTPEndPointHandlers/StaticPageHandler.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h \
		Util/String/StringUtils.h
	@mkdir -p obj/Util/Management
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Management/ManageableObject.cpp -o obj/Util/Management/ManageableObject.o

obj/Util/Management/ManageableObjectParameter.o : Util/Management/ManageableObjectParameter.cpp  \
		Util/Management/ManageableObjectParameter.h
	@mkdir -p obj/Util/Management
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Management/ManageableObjectParameter.cpp -o obj/Util/Management/ManageableObjectParameter.o

obj/Util/Management/ManagementServer.o : Util/Management/ManagementServer.cpp  \
		Util/Management/ManagementServer.h \
		Util/Server/HTTP/ThreadPoolHTTPServer.h \
		Util/Server/ThreadPoolTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h \
		Util/Thread/Thread.h \
		Util/Thread/ThreadPool.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Server/HTTP/HTTPServerBase.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h \
		Util/Management/Manageable.h \
		Util/Management/ManageableObjectParameter.h \
		Util/Management/HTTPEndPointHandlers/StaticPageHandler.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h \
		Util/Management/HTTPEndPointHandlers/PointsListerHandler.h \
		Util/Management/HTTPEndPointHandlers/PointsHandler.h
	@mkdir -p obj/Util/Management
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Management/ManagementServer.cpp -o obj/Util/Management/ManagementServer.o

obj/Util/ObjectStore/Exception/ObjectStoreException.o : Util/ObjectStore/Exception/ObjectStoreException.cpp  \
		Util/ObjectStore/Exception/ObjectStoreException.h
	@mkdir -p obj/Util/ObjectStore/Exception
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/ObjectStore/Exception/ObjectStoreException.cpp -o obj/Util/ObjectStore/Exception/ObjectStoreException.o

obj/Util/OptParse/OptParse.o : Util/OptParse/OptParse.cpp  \
		Util/OptParse/OptParse.h
	@mkdir -p obj/Util/OptParse
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/OptParse/OptParse.cpp -o obj/Util/OptParse/OptParse.o

obj/Util/Random/Sequential.o : Util/Random/Sequential.cpp  \
		Util/Random/Sequential.h \
		Util/Thread/Mutex.h
	@mkdir -p obj/Util/Random
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Random/Sequential.cpp -o obj/Util/Random/Sequential.o

obj/Util/Server/BaseTCPServer.o : Util/Server/BaseTCPServer.cpp  \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h
	@mkdir -p obj/Util/Server
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/BaseTCPServer.cpp -o obj/Util/Server/BaseTCPServer.o

obj/Util/Server/HTTP/HTTPEndPointHandler.o : Util/Server/HTTP/HTTPEndPointHandler.cpp  \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h
	@mkdir -p obj/Util/Server/HTTP
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/HTTP/HTTPEndPointHandler.cpp -o obj/Util/Server/HTTP/HTTPEndPointHandler.o

obj/Util/Server/HTTP/HTTPParser.o : Util/Server/HTTP/HTTPParser.cpp  \
		Util/Server/HTTP/HTTPParser.h \
		Util/IO/InputOutputCapable.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/IO/Structure/Line/LineReader.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/Structure/Block/BlockReader.h \
		Util/IO/InputOutputCapable.h \
		Util/String/StringUtils.h \
		Util/DataType/Primitive/Number.h \
		Util/DataType/BaseDataType.h \
		Util/Serialisable/Serialisable.h
	@mkdir -p obj/Util/Server/HTTP
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/HTTP/HTTPParser.cpp -o obj/Util/Server/HTTP/HTTPParser.o

obj/Util/Server/HTTP/HTTPServerBase.o : Util/Server/HTTP/HTTPServerBase.cpp  \
		Util/Server/HTTP/HTTPServerBase.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h
	@mkdir -p obj/Util/Server/HTTP
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/HTTP/HTTPServerBase.cpp -o obj/Util/Server/HTTP/HTTPServerBase.o

obj/Util/Server/HTTP/protocol/HTTPRequest.o : Util/Server/HTTP/protocol/HTTPRequest.cpp  \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/DataType/Primitive/Number.h \
		Util/DataType/BaseDataType.h \
		Util/Serialisable/Serialisable.h \
		Util/String/StringUtils.h
	@mkdir -p obj/Util/Server/HTTP/protocol
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/HTTP/protocol/HTTPRequest.cpp -o obj/Util/Server/HTTP/protocol/HTTPRequest.o

obj/Util/Server/HTTP/protocol/HTTPResponse.o : Util/Server/HTTP/protocol/HTTPResponse.cpp  \
		Util/Server/HTTP/protocol/HTTPResponse.h \
		Util/DataType/Primitive/Number.h \
		Util/DataType/BaseDataType.h \
		Util/Serialisable/Serialisable.h
	@mkdir -p obj/Util/Server/HTTP/protocol
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/HTTP/protocol/HTTPResponse.cpp -o obj/Util/Server/HTTP/protocol/HTTPResponse.o

obj/Util/Server/HTTP/ThreadPoolHTTPServer.o : Util/Server/HTTP/ThreadPoolHTTPServer.cpp  \
		Util/Server/HTTP/ThreadPoolHTTPServer.h \
		Util/Server/ThreadPoolTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h \
		Util/Thread/Thread.h \
		Util/Thread/ThreadPool.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Server/HTTP/HTTPServerBase.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h \
		Util/Server/HTTP/HTTPParser.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/Structure/Block/BlockWriter.h \
		Util/IO/InputOutputCapable.h
	@mkdir -p obj/Util/Server/HTTP
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/HTTP/ThreadPoolHTTPServer.cpp -o obj/Util/Server/HTTP/ThreadPoolHTTPServer.o

obj/Util/Server/RequestProcessors/ForkingRequestProcessor.o : Util/Server/RequestProcessors/ForkingRequestProcessor.cpp  \
		
	@mkdir -p obj/Util/Server/RequestProcessors
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/RequestProcessors/ForkingRequestProcessor.cpp -o obj/Util/Server/RequestProcessors/ForkingRequestProcessor.o

obj/Util/Server/RequestProcessors/ThreadingRequestProcessor.o : Util/Server/RequestProcessors/ThreadingRequestProcessor.cpp  \
		Util/Server/RequestProcessors/ThreadingRequestProcessor.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Thread/Thread.h
	@mkdir -p obj/Util/Server/RequestProcessors
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/RequestProcessors/ThreadingRequestProcessor.cpp -o obj/Util/Server/RequestProcessors/ThreadingRequestProcessor.o

obj/Util/Server/RequestProcessors/ThreadPoolRequestProcessor.o : Util/Server/RequestProcessors/ThreadPoolRequestProcessor.cpp  \
		Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Thread/Thread.h \
		Util/Thread/ThreadPool.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h
	@mkdir -p obj/Util/Server/RequestProcessors
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/RequestProcessors/ThreadPoolRequestProcessor.cpp -o obj/Util/Server/RequestProcessors/ThreadPoolRequestProcessor.o

obj/Util/Server/ServerSkeleton.o : Util/Server/ServerSkeleton.cpp  \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h
	@mkdir -p obj/Util/Server
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/ServerSkeleton.cpp -o obj/Util/Server/ServerSkeleton.o

obj/Util/Server/test/ThreadingTCPServerTest.o : Util/Server/test/ThreadingTCPServerTest.cpp  \
		Util/Server/ThreadingTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadingRequestProcessor.h \
		Util/Thread/Thread.h \
		Util/IO/Structure/Line/LineReader.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/Structure/Line/LineWriter.h \
		Util/IO/SocketIO/TCPClientSocket.h \
		Util/Thread/Mutex.h \
		Util/Thread/ThreadLogger.h
	@mkdir -p obj/Util/Server/test
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/test/ThreadingTCPServerTest.cpp -o obj/Util/Server/test/ThreadingTCPServerTest.o

obj/Util/Server/test/ThreadPoolHTTPServerTest.o : Util/Server/test/ThreadPoolHTTPServerTest.cpp  \
		Util/Server/HTTP/ThreadPoolHTTPServer.h \
		Util/Server/ThreadPoolTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h \
		Util/Thread/Thread.h \
		Util/Thread/ThreadPool.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/Server/HTTP/HTTPServerBase.h \
		Util/Server/HTTP/HTTPEndPointHandler.h \
		Util/Server/HTTP/protocol/HTTPRequest.h \
		Util/Server/HTTP/protocol/HTTPEndPoint.h \
		Util/Server/HTTP/protocol/HTTPResponse.h
	@mkdir -p obj/Util/Server/test
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/test/ThreadPoolHTTPServerTest.cpp -o obj/Util/Server/test/ThreadPoolHTTPServerTest.o

obj/Util/Server/test/ThreadPoolTCPServerTest.o : Util/Server/test/ThreadPoolTCPServerTest.cpp  \
		Util/Server/ThreadPoolTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h \
		Util/Thread/Thread.h \
		Util/Thread/ThreadPool.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h \
		Util/IO/Structure/Line/LineReader.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/Structure/Line/LineWriter.h \
		Util/IO/SocketIO/TCPClientSocket.h \
		Util/Thread/Mutex.h \
		Util/Thread/ThreadLogger.h
	@mkdir -p obj/Util/Server/test
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/test/ThreadPoolTCPServerTest.cpp -o obj/Util/Server/test/ThreadPoolTCPServerTest.o

obj/Util/Server/ThreadingTCPServer.o : Util/Server/ThreadingTCPServer.cpp  \
		Util/Server/ThreadingTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadingRequestProcessor.h \
		Util/Thread/Thread.h
	@mkdir -p obj/Util/Server
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/ThreadingTCPServer.cpp -o obj/Util/Server/ThreadingTCPServer.o

obj/Util/Server/ThreadPoolTCPServer.o : Util/Server/ThreadPoolTCPServer.cpp  \
		Util/Server/ThreadPoolTCPServer.h \
		Util/Server/BaseTCPServer.h \
		Util/Server/ServerSkeleton.h \
		Util/IO/SocketIO/TCPServerSocket.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/Connection.h \
		Util/Server/RequestProcessors/RequestProcessor.h \
		Util/IO/SocketIO/Connection.h \
		Util/IO/InputOutputCapable.h \
		Util/IO/SocketIO/SocketException.h \
		Util/IO/SocketIO/TCPSocket.h \
		Util/IO/SocketIO/Socket.h \
		Util/Server/RequestProcessors/ThreadPoolRequestProcessor.h \
		Util/Thread/Thread.h \
		Util/Thread/ThreadPool.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h
	@mkdir -p obj/Util/Server
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Server/ThreadPoolTCPServer.cpp -o obj/Util/Server/ThreadPoolTCPServer.o

obj/Util/String/StringUtils.o : Util/String/StringUtils.cpp  \
		Util/String/StringUtils.h
	@mkdir -p obj/Util/String
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/String/StringUtils.cpp -o obj/Util/String/StringUtils.o

obj/Util/String/test/main.o : Util/String/test/main.cpp  \
		Util/String/StringUtils.h
	@mkdir -p obj/Util/String/test
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/String/test/main.cpp -o obj/Util/String/test/main.o

obj/Util/Thread/Condition.o : Util/Thread/Condition.cpp  \
		Util/Thread/Condition.h \
		Util/Thread/Mutex.h \
		Util/Time/Time.h
	@mkdir -p obj/Util/Thread
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/Condition.cpp -o obj/Util/Thread/Condition.o

obj/Util/Thread/Mutex.o : Util/Thread/Mutex.cpp  \
		Util/Thread/Mutex.h
	@mkdir -p obj/Util/Thread
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/Mutex.cpp -o obj/Util/Thread/Mutex.o

obj/Util/Thread/ReadWriteLock.o : Util/Thread/ReadWriteLock.cpp  \
		Util/Thread/ReadWriteLock.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h
	@mkdir -p obj/Util/Thread
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/ReadWriteLock.cpp -o obj/Util/Thread/ReadWriteLock.o

obj/Util/Thread/test/prodcons.o : Util/Thread/test/prodcons.cpp  \
		Util/Thread/Thread.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h
	@mkdir -p obj/Util/Thread/test
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/test/prodcons.cpp -o obj/Util/Thread/test/prodcons.o

obj/Util/Thread/test/ThreadPoolTest.o : Util/Thread/test/ThreadPoolTest.cpp  \
		Util/Thread/ThreadPool.h \
		Util/Thread/Thread.h \
		Util/Thread/ThreadLogger.h \
		Util/Thread/SynchronisedQueue.h \
		Util/Thread/Mutex.h \
		Util/Thread/Condition.h \
		Util/Time/Time.h
	@mkdir -p obj/Util/Thread/test
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/test/ThreadPoolTest.cpp -o obj/Util/Thread/test/ThreadPoolTest.o

obj/Util/Thread/test/ThreadTest.o : Util/Thread/test/ThreadTest.cpp  \
		Util/Thread/Thread.h \
		Util/Thread/Mutex.h \
		Util/Thread/ThreadLogger.h
	@mkdir -p obj/Util/Thread/test
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/test/ThreadTest.cpp -o obj/Util/Thread/test/ThreadTest.o

obj/Util/Thread/Thread.o : Util/Thread/Thread.cpp  \
		Util/Thread/Thread.h
	@mkdir -p obj/Util/Thread
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/Thread.cpp -o obj/Util/Thread/Thread.o

obj/Util/Thread/ThreadLogger.o : Util/Thread/ThreadLogger.cpp  \
		Util/Thread/ThreadLogger.h \
		Util/Thread/Mutex.h
	@mkdir -p obj/Util/Thread
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/ThreadLogger.cpp -o obj/Util/Thread/ThreadLogger.o

obj/Util/Thread/ThreadPool.o : Util/Thread/ThreadPool.cpp  \
		
	@mkdir -p obj/Util/Thread
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Thread/ThreadPool.cpp -o obj/Util/Thread/ThreadPool.o

obj/Util/Time/Time.o : Util/Time/Time.cpp  \
		Util/Time/Time.h
	@mkdir -p obj/Util/Time
	$(CPPCOMPILER) $(COMPILEFLAGS) $(PREPROCESSORDEFINES) -c Util/Time/Time.cpp -o obj/Util/Time/Time.o

clean:
	@rm -rf obj
	@echo Cleaned!
