/*
 * Ruby extension to expose the conversion methods of WBXML,
 * the WAP XML to XML (and back) converter.
 *
 * Copyright 2008 Clifford Heath. SOME RIGHTS RESERVED, READ THE COPYRIGHT.
 * This work was paid for by Gekocard Pty Ltd for http://mobiblast.com
 */
#include <ruby.h>
#include <wbxml.h> /* libwbxml2 */

VALUE mWBXML;		/* The WBXML module object */

VALUE
xml_to_wbxml(VALUE self, VALUE xml_source)
{
	WBXMLError	ret = WBXML_OK;
	WBXMLConvXML2WBXMLParams params;
	WB_UTINY*	xml = NULL;		/* Must be null terminated */
	WB_UTINY*	wbxml = NULL;
	WB_ULONG	wbxml_len = 0;
	VALUE		value;

	Check_SafeStr(xml_source);
	if (TYPE(xml_source) != T_STRING)
		rb_raise(rb_eTypeError, "parameter to xml_to_wbxml must be a string");
	xml = (WB_UTINY*)STR2CSTR(xml_source);

	params.wbxml_version = WBXML_VERSION_13;
	params.use_strtbl = TRUE;
	params.keep_ignorable_ws = FALSE;

	ret = wbxml_conv_xml2wbxml(xml, &wbxml, &wbxml_len, &params);
	if (ret != WBXML_OK)
		rb_raise(rb_eRuntimeError, (const char*)wbxml_errors_string(ret));

	value = rb_str_new((const char*)wbxml, wbxml_len);

	if (wbxml != NULL)
		wbxml_free(wbxml);
	return value;
}

VALUE
wbxml_to_xml(VALUE self, VALUE wbxml_source)
{
	WBXMLError	ret = WBXML_OK;
	WBXMLConvWBXML2XMLParams	params;
	WB_UTINY*	wbxml = NULL;
	WB_ULONG	wbxml_len = 0;
	WB_UTINY*	xml = NULL;		/* Must be null terminated */
	VALUE		value;

	Check_SafeStr(wbxml_source);
	if (TYPE(wbxml_source) != T_STRING)
		rb_raise(rb_eTypeError, "parameter to wbxml_to_xml must be a string");
	wbxml = (WB_UTINY*)STR2CSTR(wbxml_source);
	wbxml_len = RSTRING_LEN(wbxml_source);

	params.gen_type = WBXML_ENCODER_XML_GEN_INDENT;
	params.lang = WBXML_LANG_UNKNOWN;	/* Don't force the language */
	params.indent = 2;
	params.keep_ignorable_ws = FALSE;

	ret = wbxml_conv_wbxml2xml(wbxml, wbxml_len, &xml, &params);
	if (ret != WBXML_OK)
		rb_raise(rb_eRuntimeError, (const char*)wbxml_errors_string(ret));

	value = rb_str_new((const char*)xml, strlen(xml));

	if (xml != NULL)
		wbxml_free(xml);
	return value;
}

void
Init_wbxml()
{
	mWBXML = rb_define_module("WBXML");
	rb_define_singleton_method(mWBXML, "xml_to_wbxml", xml_to_wbxml, 1);
	rb_define_singleton_method(mWBXML, "wbxml_to_xml", wbxml_to_xml, 1);
}
