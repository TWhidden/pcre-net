﻿using NUnit.Framework;

namespace PCRE.Tests
{
    [TestFixture]
    public class PcrePatternInfoTests
    {
        [Test]
        [TestCase(@"a", 0)]
        [TestCase(@"(a)(b)", 2)]
        [TestCase(@"(a)(b(c))", 3)]
        public void should_return_capture_count(string pattern, int expected)
        {
            var re = new Pcre(pattern);
            Assert.That(re.PaternInfo.CaptureCount, Is.EqualTo(expected));
        }

        [Test]
        [TestCase(@"a", 1)]
        [TestCase(@"(a)(b)", 2)]
        [TestCase(@"a{3,5}b", 4)]
        public void should_detect_min_subject_length(string pattern, int expected)
        {
            var re = new Pcre(pattern, PcreOptions.Study);
            Assert.That(re.PaternInfo.MinSubjectLength, Is.EqualTo(expected));
        }

        [Test]
        [TestCase(@"a")]
        [TestCase(@"ab?ac?")]
        public void should_compile_pattern(string pattern)
        {
            var re = new Pcre(pattern, PcreOptions.Compiled);
            Assert.That(re.PaternInfo.IsCompiled, Is.True);
        }
    }
}
