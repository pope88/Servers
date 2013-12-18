@echo off
SsuGen PacketsCtoLS.proto ../Packet/PacketsCtoLS.cpp ../Packet/PacketsCtoLS.h
SsuGen PacketsLStoC.proto ../Packet/PacketsLStoC.cpp ../Packet/PacketsLStoC.h
protoa PacketsLStoC.proto ../Packet/Builder.inl LSC PacketsCtoLS.proto ../Packet/Handlerclient/ CLS
protodoc PacketsLStoC.proto PacketsCtoLS.proto > ClientAndLoginServerDoc.html
