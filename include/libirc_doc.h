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
 * \file libirc_doc.h
 * \author Georgy Yunaev
 * \version 1.0
 * \date 09.2004
 * \brief This file contains Doxygen modules.
 */

/*! \mainpage libircclient - a IRC library to create IRC clients
 *
 * \section intro_sec Introduction
 *
 * libircclient is a small but powerful library, which implements client-server IRC
 * protocol. It is designed to be small, fast, portable and compatible to RFC
 * standards, and most IRC clients. libircclient features include:
 * - Full multi-threading support.
 * - Single threads handles all the IRC processing.
 * - Support for single-threaded applications, and socket-based applications, 
 *   which use select()
 * - Synchronous and asynchronous interfaces.
 * - CTCP support with optional build-in reply code.
 * - Flexible DCC support, including both DCC chat, and DCC file transfer.
 * - Can both initiate and react to initiated DCC.
 * - Can accept or decline DCC sessions asynchronously.
 * - Plain C interface and implementation (possible to use from C++ code, 
 *   obviously)
 * - Compatible with RFC 1459 and most IRC clients.
 * - Free, licensed under LGPL license.
 * - Good documentation and examples available.
 *
 * \section install_sec Compilation
 *
 * To compile libircclient, unpack the distribution, and do the standard mantra:
 * \code
 * # ./configure
 * # make
 * # make install
 * \endcode
 *  
 * \section doc Documentation
 *
 * Documentation is not installed with \a make \a install; you should copy it
 * somewhere by hand.
 * There is html documentation (in \a doc/html) and manual pages (\a doc/man).
 * It is also recommended to check the \a examples directory, there are a 
 * few examples, they'll help you.
 * 
 * \section author Author, copyright, support.
 *
 * If you have any questions, bug reports, suggestions regarding libircclient - 
 * please send them to tim@krasnogorsk.ru.
 *
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
 */


/*!
 * \defgroup initclose Initiating and destroying IRC session 
 */

/*!
 * \defgroup conndisc  Connecting, disconnecting from IRC server
 */

/*!
 * \defgroup running   Running IRC session.
 */

/*!
 * \defgroup sendcmds  Sending IRC commands.
 */

/*!
 * \defgroup ctcp      CTCP requests and replies.
 */

/*!
 * \defgroup nnparse   Nickname parsing.
 */

/*!
 * \defgroup dccstuff  DCC chat/send requests and replies.
 */

/*!
 * \defgroup events    Handling IRC events.
 */

/*!
 * \defgroup errors    Obtaining error values and descriptions.
 */

/*!
 * \defgroup contexts  Managing contexts.
 */
 
/*!
 * \defgroup common    Getting libircclient version.
 */

/*!
 * \defgroup options    Managing libircclient options.
 */
