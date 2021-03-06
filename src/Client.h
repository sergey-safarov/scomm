
/***************************************************************************
 *   Copyright (C) 2007 by PAX   *
 *   pax@m-200.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef CLIENT_H
#define CLIENT_H

#include "protocol.h"

class CClient
{
    void ReceivePacket(unsigned char *buff, short size);        //zapis v txbuf
  public:
      bool state;
    bool fBinaryRead;
    bool fBinaryWrite;
    unsigned char recvBuf[10000];
    int con;
    int fd;
    int recvLen;
    char IP[16];

    CPPP *m_ppp;
    void SendPacket(unsigned char *buff, short size);   //otpravka paketa klientu
    void OnReceive(unsigned char *buff, short size);    //prijem i obrabotka paketa ot klienta
      CClient(int file_description, int con, const char *ip, CPPP * _ppp);
     ~CClient();
};
#endif
