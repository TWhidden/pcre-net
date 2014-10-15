
#pragma once

#include "PatternInfoKey.h"
#include "PcrePatternOptions.h"
#include "PcreStudyOptions.h"
#include "MatchOffsets.h"

using namespace System;

namespace PCRE {
	namespace Wrapper {

		public ref class PcrePattern sealed
		{
		public:
			PcrePattern(String^ pattern, PcrePatternOptions options, Nullable<PcreStudyOptions> studyOptions);
			~PcrePattern();
			!PcrePattern();

			bool IsMatch(String^ subject);
			MatchOffsets FirstMatch(String^ subject);

			int GetInfoInt32(PatternInfoKey key);

			property int CaptureCount {
				int get() { return _captureCount; }
			}

		private:
			pcre16* _re;
			pcre16_extra* _extra;
			int _captureCount;
		};
	}
}
