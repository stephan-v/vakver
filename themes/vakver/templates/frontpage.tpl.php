<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="header index-header" style="background-image: url(<?php print file_create_url($node->field_image['und'][0]['uri']); ?>)"></div><!-- /.header -->

    <div class="sort-bar">
        <div class="container">
            <ul class="list-inline pull-left">
                <li>Sorteer op</li>
                <li>Test</li>
                <li>NOg een item</li>
            </ul>

            <ul class="list-inline pull-right">
                <li>89380 vakanties gevonden</li>
            </ul>
        </div><!-- /.container -->
    </div>

    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <div class="main-content">
        <aside>
            <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Labore aut alias, iure delectus voluptate cum unde, odio animi eveniet quas quos provident nemo, architecto qui illum iste ea perspiciatis rerum.</p>
        </aside>

        <div class="container">
            <!-- elasticsearch results(tag is located at: js/components/elasticsearch.vue) -->
            <elasticsearch></elasticsearch>
        </div><!-- /.container -->
    </div><!-- /.main-content -->
</div><!-- /#node -->
