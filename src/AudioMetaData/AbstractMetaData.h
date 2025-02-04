#pragma once

#include <stdint.h>

namespace audio_tools {

/// Type of meta info
enum MetaDataType { Title, Artist, Album, Genre, Name, Description };

/// Test Description for meta info
const char* MetaDataTypeStr[] = {"Title", "Artist", "Album", "Genre","Name", "Description"};

/// Converts the MetaDataType to a string
const char *toStr(MetaDataType t){
    return MetaDataTypeStr[t];
}

/**
 * @brief Common Metadata methods
 * 
 */
class AbstractMetaData {
    public:
        // defines the callback which provides the metadata information
        virtual void setCallback(void (*fn)(MetaDataType info, const char* str, int len)) = 0 ;
        // starts the processing
        virtual void begin() = 0;
        // ends the processing
        virtual void end() = 0;
        // provide audio data which contains the metadata to be extracted
        virtual size_t write(const uint8_t *data, size_t length) = 0;
        // select Icecast/Shoutcast Metadata
        virtual void setIcyMetaInt(int value){}

};

}