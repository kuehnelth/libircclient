/* 
 * Copyright (C) 2004 Georgy Yunaev tim@krasnogorsk.ru
 *
 * This library is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU Lesser General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or (at your 
 * option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public 
 * License for more details.
 *
 * $Id$
 */

/*! 
 * \file libirc_doc_faq.h
 * \author Georgy Yunaev
 * \version 1.0
 * \date 09.2004
 * \brief This file contains libircclient FAQ.
 */

/*! \page pagefaq Frequently Asked Questions

\section faq FAQ

\subsection faq1 Why the IRC server generates all these event_numeric events, and what they are?

The IRC protocol itself is asynchronous and server-driven. 
For you, this means the following:
- For any IRC command, it is not possible to obtain an immediate response
  whether the command succeed or not. Instead the server will send the 
  reply in a short (or long) period of time.
- For some IRC command there is no 'success' response at all. For example,
  when you send a text message, IRC server will not send anything to confirm
  that the message is already sent.
- You can send several commands to the IRC server, and then receive several
  replies regarding every command. The order of the replies you receive
  is generally undefined.
- A lot of IRC events sent to you is generated by other users, or the IRC 
  server itself, and are sent to you just when they are generated.
- Long lists (for example, channel lists) are also sent as events. Moreover,
  these events could be separated by other events (message or notices). And
  it is your responsibility to separate the data (using event codes), and
  use some sort of data structure that will hold it until the data is 
  complete. It is not possible to simply query the list of channels, and 
  expect that its content will immediately arrive.
- IRC protocol is event-based, not request-based. This means that if you
  send JOIN request asking to join a channel, you cannot assume that you 
  have joined it until the server tells you so with JOIN event. Also it is
  possible for server to "JOIN" you to a specific channel implicitly, 
  without even sending a join request.
- You should be prepared to expect the unexpected from the IRC server. 
  For example, the server can change your nick (seen on most servers, which
  use \a nickserv authentication. You can be "forced" to join the channel,
  to say something, to leave a channel, to change your usermode and so on.
  Listen what IRC server tells you, and do so.

\subsection faq2 Why the irc_cmd_... functions does not return an error if the IRC server reports it? For example, why irc_cmd_join() returns success when I attempt to join a password-protected channel, and then the IRC server sends an error?

The irc_cmd_... functions return success when the command is sent to the 
IRC server. The asynchronous nature of IRC makes it impossible to obtain
the command result immediately. Please read \ref faq1.

\subsection faq3 How to register/auth with NICKSERV?

There is no 'standard' way. However, knowing that all NICKSERV messages are 
sent via irc_callbacks_t::event_notice, you can use following algorithm:
\code
static void event_notice (irc_session_t * session, const char * event, 
             const char * origin, const char ** params, unsigned int count)
{
	char buf[256];

	if ( !origin )
		return;

	if ( strcasecmp (origin, "nickserv") )
		return;

	if ( strstr (params[1], "This nick is not registered") == params[1] )
	{
		sprintf (buf, "REGISTER %s NOMAIL", gCfg.irc_nickserv_password);
		irc_cmd_msg (session, "nickserv", buf);
	}
	else if ( strstr (params[1], "This nickname is registered and protected") 
	  == params[1] )
	{
		sprintf (buf, "IDENTIFY %s", gCfg.irc_nickserv_password);
		irc_cmd_msg (session, "nickserv", buf);
	}
	else if ( strstr (params[1], "Password accepted - you are now recognized") 
	  == params[1] )
		printf ("Nickserv authentication succeed.");
}
\endcode

The idea is to parse the messages sent from NICKSERV, and if they're matched
the specific patterns, react on them appropriately.

\subsection faq4 What is CTCP, and why do I need my own handler?

CTCP abbreviature is deciphered as "Client-to-Client Protocol". It is used 
between the IRC clients to query the remote client for some data, or to send 
some information - for example, /me messages are sent via CTCP. There is no
standard list of possible CTCP requests, and different IRC clients often add
their own CTCP codes. The built-in handler reacts on TIME, VERSION, PING and
FINGER CTCP queries. If you need to react on other queries, you'll have to 
write your own CTCP handler. See the source code of libirc_event_ctcp_internal
to get an idea how to write it.

 */
