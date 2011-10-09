#include "qstring.h"
#include "encoder4.h"

#define CHAR_TO_HEX(c)		((c) < 0xA ? '0' + (c) : ('A' - 0xA) + (c))
#define HEX_TO_CHAR(h)		((h) > 'A' ? (h) - ('A' - 0xA) : (h) - '0')

/**
 * Class constructor.
 */
Encoder::Encoder() : m_pBuf(NULL), m_nBufLen(0)
{
}
	
/**
 * Class destructor.
 */
Encoder::~Encoder() { 
	if (m_pBuf) 
		delete[] m_pBuf; 
}
	
/**
 * Encodes a string.
 * @param	str	The string to encode
 * @return	The hex-encoded ASCII string
 */
const char* Encoder::encode(const QString& str)
{
	const char* szStr;
	int nLen, i, j;
		
	szStr = str.toLatin1();
	nLen = str.length();
		
	// Ensure the buffer is big enough to contain the result
	resize((nLen * 2) + 1);
		
	// Encode the string
	for (i = 0, j = 0; i < nLen; i++, j += 2) {
		m_pBuf[j] = CHAR_TO_HEX(szStr[i] >> 4);
		m_pBuf[j + 1] = CHAR_TO_HEX(szStr[i] & 0x0f);
	}
		
	m_pBuf[j] = 0;
	return m_pBuf;
}
	
/**
 * Decodes a string.
 * @param	str	The string to decode
 * @return	The decoded string.
 */
const char* Encoder::decode(const QString& str)
{
	const char* szStr;
	int nLen, i, j;
		
	szStr = str.toLatin1();
	nLen = str.length();
		
	// Ensure the buffer is big enough to contain the result
	nLen /= 2;
	resize(nLen + 1);
	
	// Decode the string
	for (i = 0, j = 0; i < nLen; i++, j += 2) {
		m_pBuf[i] = HEX_TO_CHAR(szStr[j]) << 4;
		m_pBuf[i] |= HEX_TO_CHAR(szStr[j + 1]);
	}
		
	m_pBuf[i] = 0;
	return m_pBuf;
}
	
/**
 * Sets a new size to the buffer.
 * @param	nNewLen	The new size of the buffer
 */
void Encoder::resize(int nNewLen)
{
	if (m_nBufLen < nNewLen) {
		if (m_pBuf)
			delete[] m_pBuf;
				
		m_pBuf = new char[nNewLen];
	}
}
