#ifndef __ENCODER_H
#define __ENCODER_H

/**
 * Translates strings to hex-encoded ASCII, and vice-versa.
 * @author Elad Lahav
 */
class Encoder
{
public:
	Encoder();
	~Encoder();
	const char* encode(const QString&);
	const char* decode(const QString&);
	
private:
	/** A buffer to contain the result of encoding/decoding. */
	char* m_pBuf;
	
	/** The buffer's length. */
	int m_nBufLen;

	void resize(int);
};

#endif

// Sat Oct  8 16:12:23 PDT 2011
