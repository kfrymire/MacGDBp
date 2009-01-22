/*
 * MacGDBp
 * Copyright (c) 2007 - 2009, Blue Static <http://www.bluestatic.org>
 * 
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU 
 * General Public License as published by the Free Software Foundation; either version 2 of the 
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without 
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with this program; if not, 
 * write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#import <Cocoa/Cocoa.h>
#import "SocketWrapper.h"
#import "Breakpoint.h"
#import "StackFrame.h"

extern NSString *kErrorOccurredNotif;

@interface GDBpConnection : NSObject
{
	int port;
	NSString *session;
	BOOL connected;
	
	/**
	 * Human-readable status of the connection
	 */
	NSString *status;
	
	SocketWrapper *socket;
}

@property(readonly, copy) NSString *status;
@property(readonly) SocketWrapper *socket;

// initializer
- (id)initWithPort:(int)aPort session:(NSString *)aSession;

// getter
- (int)port;
- (NSString *)session;
- (NSString *)remoteHost;
- (BOOL)isConnected;

// communication
- (void)reconnect;
- (void)run;
- (StackFrame *)stepIn;
- (StackFrame *)stepOut;
- (StackFrame *)stepOver;
- (void)addBreakpoint:(Breakpoint *)bp;
- (void)removeBreakpoint:(Breakpoint *)bp;

// helpers
- (NSArray *)getProperty:(NSString *)property;

@end
