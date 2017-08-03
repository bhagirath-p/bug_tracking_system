<?php
   require_once("../inc/application.inc");
   $appln = new application($_POST,$_GET);
   $appln->run();
?>
