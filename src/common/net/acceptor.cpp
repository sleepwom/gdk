#include <net/acceptor.h>

CAcceptor::CAcceptor()
{

}

CAcceptor::~CAcceptor()
{

}

int32 CAcceptor::open( const std::string& strIP, uint16 nPort )
{
	int32 nRetCode = -1;

	if ( m_pListenSocket == NULL )
		m_pListenSocket = new CTCPSocket();

	if ( m_pListenSocket->getHandle() != INVALID_SOCKET )
		m_pListenSocket->close();

	nRetCode = m_pListenSocket->create();
	if ( nRetCode != 0 )
		return nRetCode;

	return m_pListenSocket->listen( strIP, nPort );
}

SOCKET CAcceptor::getHandle()
{
	if ( m_pListenSocket == NULL )
		return 0;
	else
		return m_pListenSocket->getHandle();
}

void CAcceptor::close()
{
	m_pListenSocket->close();
}

void CAcceptor::setListener( IAcceptorListenerPtr pListener )
{
	m_pListener = pListener;
}

IAcceptorListenerPtr CAcceptor::getListener()
{
	return m_pListener;
}

CTCPSocket* CAcceptor::accept( struct sockaddr *lpAddr, socklen_t *nAddrlen )
{
	return m_pListenSocket->accept( lpAddr, nAddrlen );
}
